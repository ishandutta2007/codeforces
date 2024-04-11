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
	while (*sdbg != ','){cerr << *sdbg++;}cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
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

const int N = 2E5 + 10;

int n;
vector<int> E[N];
ll f[N][2];
ll ans;

void DFS(int u, int pre){
	f[u][0] = f[u][1] = 0;
	for (auto v: E[u]){
		if (v == pre)
			continue;
		DFS(v, u);

		ans += (f[v][0] + f[v][1]) * (n - f[v][0] - f[v][1]);
		ans -= f[u][0] * f[v][0];
		ans -= f[v][1] * (n - f[v][0] - f[v][1]);
		f[u][0] += f[v][0], f[u][1] += f[v][1];
	}
	swap(f[u][0], f[u][1]);
	++f[u][0];

	eput(ans, f[u][0], f[u][1]);
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}

	DFS(1, 0);
	printf("%lld\n", ans);
	return 0;
}