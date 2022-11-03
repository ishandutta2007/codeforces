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

const int N = 1E6 + 10;

int n, m;
vector<pii> E[N];

int tot;
int dfn[N], low[N];
int top, sta[N], in[N];
int id[N];

vector<pii> G[N];
ll val[N], f[N];

void DFS(int u){
	dfn[u] = low[u] = ++tot;
	sta[top++] = u;
	in[u] = true;
	for (auto &x: E[u]){
		int v = x.st;
		if (!dfn[v]){
			DFS(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]){
		do{
			int u = sta[--top];
			in[u] = false;
			id[u] = m;
		}while (sta[top] != u);
		++m;
	}
}

ll calc(int x){
	int t = max<int>(0, sqrt(x << 1) - 5);
	for (; t * (t + 1) / 2 < x; ++t);
	--t;
	return (t + 1ll) * x - t * (t + 1ll) * (t + 2) / 6;
}

ll solve(int u){
	if (f[u] >= 0)
		return f[u];
	f[u] = 0;
	for (auto &x: G[u])
		f[u] = max(f[u], solve(x.st) + x.nd);
	return f[u] += val[u];
}

int main(){
	int tm;
	scanf("%d%d", &n, &tm);
	for (int i = 0; i < tm; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[u].emplace_back(v, w);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			DFS(i);
	for (int i = 1; i <= n; ++i)
		for (auto &x: E[i])
			if (id[i] == id[x.st])
				val[id[i]] += calc(x.nd);
			else
				G[id[i]].emplace_back(id[x.st], x.nd);

	fill_n(f, m, -1);
	int s;
	scanf("%d", &s);
	printf("%lld\n", solve(id[s]));
	return 0;
}