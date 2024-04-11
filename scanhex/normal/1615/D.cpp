#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N=200200;
vector<pair<int,int>> g[N];
vector<pair<int,int>> eq[N];

int p[N];
int change[N];
int col[N];
int sz[N];
pair<int, int> getp(int x) {
	if (x == p[x]) 
		return {x, 0};
	auto res = getp(p[x]);
	res.second ^= change[x];
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m; 
		cin >> n >> m;
		for(int i= 0; i < n; ++i) g[i].clear();
		vector<array<int,3>> rofl;
		for(int j = 0; j < n - 1; ++j) {
			 int a, b, v;
			 cin >> a >> b >> v;
			 --a, --b;
			 rofl.push_back({a, b, v});
		}
		vector<array<int,3>> qs(m);
		iota(p, p + n, 0);
		fill(col, col + n, -1);
		fill(sz, sz + n, 1);
		col[0] = 0;
		bool bad = false;
		for(auto&[a,b,c]:qs) {
			cin >> a >> b >> c;
			--a,--b;
		}
		for(auto& [a, b, c] : rofl)
			if (c != -1)
				qs.push_back({a,b,__builtin_popcount(c) % 2});
		for(auto& [a, b, c] : qs) {
			auto resa = getp(a);
			auto resb = getp(b);
			if (resa.first == resb.first) {
				if ((resa.second ^ resb.second ^ c) == 1) {
					bad = true;
					break;
				}
			}
			else {
				if (sz[resa.first] > sz[resb.first])
					swap(resa, resb);
				sz[resb.first] += sz[resa.first];
				p[resa.first] = resb.first;
				change[resa.first] = c ^ resa.second ^ resb.second;
			}
		}
		if (bad) {
			cout << "NO\n";
			continue;
		}
		vector<array<int,3>> res;
		for(auto& [a, b, c] : rofl) {
			if (c != -1) {
				res.push_back({a,b,c});
				continue;
			}
			auto resa = getp(a);
			auto resb = getp(b);
			if (resa.first == resb.first) {
				c = resa.second ^ resb.second;
			}
			else {
				c = 0;
				if (sz[resa.first] > sz[resb.first])
					swap(resa, resb);
				sz[resb.first] += sz[resa.first];
				p[resa.first] = resb.first;
				change[resa.first] = c ^ resa.second ^ resb.second;
			}
			res.push_back({a,b,c});
		}
		if (bad) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (auto& [a, b, c] : res) 
			cout << a + 1 << ' ' << b + 1 << ' ' << c << '\n';
	}
}