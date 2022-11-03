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

const int MAXN = 2E2 + 10, LOG = 27;

int n, K;
int dp[2][MAXN][MAXN * LOG];

int main(){
	scanf("%d%d", &n, &K);
	memset(dp[0], -1, sizeof(dp[0]));
	dp[0][0][0] = 0;
	int m = K * LOG;
	for (int i = 1; i <= n; ++i){
		auto (&f) = dp[i - 1 & 1];
		auto (&g) = dp[i & 1];
		for (int j = 0; j <= K; ++j)
			for (int k = 0; k <= m; ++k)
				g[j][k] = -1;

		ll t;
		scanf("%lld", &t);
		int t2 = __builtin_ctzll(t);
		int t5 = 0;
		for (ll tn = t; tn % 5 == 0; tn /= 5, ++t5);
		eput(t2, t5);
		for (int j = 0; j <= K; ++j)
			for (int k = 0; k <= m; ++k){
				if (f[j][k] == -1)
					continue;
				maxi(g[j][k], f[j][k]);
				if (j < K)
					maxi(g[j + 1][k + t5], f[j][k] + t2);
			}
	}
	int ans = 0;
	auto &f = dp[n & 1];
	for (int i = 0; i <= m; ++i)
		maxi(ans, min(i, f[K][i]));
	printf("%d\n", ans);
	return 0;
}