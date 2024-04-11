// LUOGU_RID: 95054749
// Problem: D. Social Network
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n, d, x, y;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dsu {
	int fa[N], sz[N];
	void init(int x) {rep(i, 1, x) fa[i] = i, sz[i] = 1;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		int u = find(x), v = find(y);
		if(u == v) return 0;
		if(sz[u] < sz[v]) swap(u, v);
		fa[v] = u;
		sz[u] += sz[v];
		sz[v] = 0;
		return 1;
	}
}dsu;

int main() {
	scanf("%d%d", &n, &d);
	dsu.init(n);
	int cnt = 1;
	rep(i, 1, d) {
		scanf("%d%d", &x, &y);
		cnt += !dsu.merge(x, y);
		vector<int> cb;
		rep(j, 1, n) if(dsu.find(j) == j) cb.push_back(dsu.sz[j]);
		sort(cb.begin(), cb.end(), greater<int>());
		int sz = cb.size(), ans = 0;
		rep(j, 0, min(sz, cnt) - 1) ans += cb[j];
		printf("%d\n", ans-1);
	}
	return 0;
}