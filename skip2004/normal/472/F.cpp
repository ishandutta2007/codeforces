#include<bits/stdc++.h>
#define pb emplace_back
using u32 = unsigned;
using pr = std::pair<int, int>;
using vec = std::vector<pr>;
using std::cin;
using std::cout;
using std::cerr;
int n;
u32 a[10000], b[10000];
vec v0, v1;

inline void emplace(u32* a, vec& vc, int x, int y, int warn = 1) {
	if(warn && x == y) puts("please do not xor self");
	a[x] ^= a[y], vc.pb(x, y);
}
inline void swap(u32* a, vec& vc, int x, int y) {
	if(x != y) { 
		emplace(a, vc, x, y);
		emplace(a, vc, y, x);
		emplace(a, vc, x, y);
	}
}
int p0[32], p1[32];
inline void reduce(u32* a, vec& vc, int * pos) {
	for(int i = 0;i < 32;++i) {
		pos[i] = -1;
	}
	for(int i = 0;i < n;++i) {
		for(int j = 31;j >= 0;--j) {
			if(!a[i]) break;
			if(a[i] >> j & 1) {
				if(pos[j] == -1) { pos[j] = i; break; }
				else emplace(a, vc, i, pos[j]);
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;++i) {
		cin >> a[i];
	}
	for(int i = 0;i < n;++i) {
		cin >> b[i];
	}
	reduce(a, v0, p0), reduce(b, v1, p1);
	for(int i = 0;i < 32;++i) {
		if(p1[i] != -1 && p0[i] == -1) {
			cout << -1 << '\n';
			return 0;
		}
	}
	for(int i = 31;i >= 0;--i) {
		if(p0[i] != -1) {
			if(p1[i] == -1) emplace(a, v0, p0[i], p0[i], 0), p0[i] = -1;
			else {
				u32 cur = a[p0[i]] ^ b[p1[i]];
				for(int j = i - 1;j >= 0;--j) if(cur >> j & 1) {
					if(p0[j] != -1) {
						emplace(a, v0, p0[i], p0[j]);
						cur ^= a[p0[j]];
					} else {
						cout << -1 << '\n';
						return 0;
					}
				}
				int id = std::find(p0, p0 + 32, p1[i]) - p0;
				swap(a, v0, p0[i], p1[i]);
				if(id != 32) p0[id] = p0[i];
				p0[i] = -1;
			}
		}
	}
	v0.insert(v0.end(), v1.rbegin(), v1.rend());
	for(int i = 0;i < n;++i) {
		// cerr << "debug : " << a[i] << ' ' << b[i] << '\n';
	}
	cout << v0.size() << '\n';
	for(auto i : v0) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}