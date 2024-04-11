#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int N = 5E5 + 10, M = N, W = N;

int n, m;
int u[M], v[M], w[M];
vector<int> e[W];
vector<pii> f[W];

int ts;
int fa[N], fa2[N], mark[N];

int ans[N];

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int find2(int x){
	if (mark[x] != ts)
		mark[x] = ts, fa2[x] = fa[x];
	return fa2[x] == x ? x : (fa2[x] = find2(fa2[x]));
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", u + i, v + i, w + i);
		e[w[i]].push_back(i);
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i){
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; ++j){
			int x;
			scanf("%d", &x);
			--x;
			f[w[x]].emplace_back(i, x);
		}
	}

	fill_n(ans, q, true);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i < W; ++i){
		sort(all(f[i]));
		for (int j = 0; j < f[i].size(); ++j){
			if (j == 0 || f[i][j].st != f[i][j - 1].st)
				++ts;
			int ru = find2(u[f[i][j].nd]), rv = find2(v[f[i][j].nd]);
			ans[f[i][j].st] &= ru != rv;
			fa2[ru] = rv;
		}
		for (auto &x: e[i])
			fa[find(u[x])] = find(v[x]);
	}
	for (int i = 0; i < q; ++i)
		puts(ans[i] ? "YES" : "NO");
	
	return 0;
}