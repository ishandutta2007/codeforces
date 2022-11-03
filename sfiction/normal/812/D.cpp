#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

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

const int MAXN = 1E5 + 10, MAXM = 1E5 + 10;

int n, m, K, q;
int last[MAXM], wait[MAXN];

vector<int> E[MAXN];
vector<PII> f[MAXN];

int tot, mark[MAXN];
int ans[MAXN];

void DFS(int u){
	mark[u] = true;
	++tot;
	for (auto &x: f[u])
		if (mark[x.st])
			x.st = -x.st;
	int size = tot;
	for (auto &v: E[u])
		eput(u, v), DFS(v);
	size = tot - size + 1;
	for (auto &x: f[u]){
		if (x.st > 0 && !mark[x.st])
			x.st = -x.st;
		ans[x.nd] = x.st > 0 ? size : 0;
	}
}

int main(){
	scanf("%d%d%d%d", &n, &m, &K, &q);

	for (int u, v, i = 0; i < K; ++i){
		scanf("%d%d", &u, &v);
		if (!last[v])
			last[v] = u;
		else if (!wait[u])
			E[last[v]].push_back(u), wait[u] = true, last[v] = u;
	}
	for (int i = 1; i <= n; ++i)
		if (!wait[i])
			E[0].push_back(i);

	for (int u, v, i = 0; i < q; ++i){
		scanf("%d%d", &u, &v);
		f[u].emplace_back(last[v], i);
	}
	DFS(0);

	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}