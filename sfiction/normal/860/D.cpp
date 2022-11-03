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

const int MAXN = 2E5 + 10, MAXM = 2E5 + 10;

int n, m;
vector<pii> E[MAXN];
int vis[MAXN];
int mark[MAXM];

int r, s[MAXN][3];

bool DFS(int u, int pre){
	vis[u] = true;
	vector<int> a;
	for (auto &x: E[u]){
		if (mark[x.nd])
			continue;
		mark[x.nd] = true;

		int v = x.st;
		if (vis[v])
			a.emplace_back(v);
		else{
			if (DFS(v, u))
				a.emplace_back(v);
		}
	}

	for (int i = 1; i < a.size(); i += 2){
		s[r][0] = a[i - 1];
		s[r][1] = u;
		s[r][2] = a[i];
		++r;
	}
	if (a.size() & 1 && pre != 0){
		s[r][0] = a.back();
		s[r][1] = u;
		s[r][2] = pre;
		++r;
	}
	return !(a.size() & 1);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].emplace_back(v, i);
		E[v].emplace_back(u, i);
	}

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			DFS(i, 0);

	printf("%d\n", r);
	for (int i = 0; i < r; ++i)
		printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
	return 0;
}