#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
const int N = 100000;
struct T { int a[5], w; };
inline bool cmp(const T & x, const T & y) {
	return x.w < y.w;
}
using std::cin;
using std::cout;
int n, m;
T a[N];
std::map<int, std::vector<int>> mp0;
std::map<int, std::bitset<N>> mp1;
const int lim = 200;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < m;++j) cin >> a[i].a[j];
		cin >> a[i].w;
	}
	std::sort(a, a + n, cmp);
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < m;++j) {
			mp0[a[i].a[j]].push_back(i);
		}
	}
	for(const auto & x : mp0) {
		if(x.second.size() >= lim) {
			auto & z = mp1[x.first];
			for(int y : x.second) z.set(y);
		}
	}
	int ans = 2e9 + 5;
	for(int i = 0;i < n;++i) {
		static std::bitset<N> ep; ep.reset();
		for(int j = 0;j < m;++j) {
			const auto & x = mp0[a[i].a[j]];
			if(x.size() >= lim) {
				ep |= mp1[a[i].a[j]];
			} else {
				for(int y : x) ep.set(y);
			}
		}
		int z = (~ep)._Find_first();
		if(z < n)
			ans = std::min(ans, a[i].w + a[z].w);
	}
	cout << (ans <= 2e9 ? ans : -1) << '\n';
}