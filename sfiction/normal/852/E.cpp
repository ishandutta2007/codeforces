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

const int MAXN = 1E6 + 10, MOD = 1E9 + 7;

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

int cnt[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		++cnt[u], ++cnt[v];
	}
	int m = 0;
	for (int i = 1; i <= n; ++i)
		m += cnt[i] == 1;
	printf("%lld\n", (n + m) * modExp(2, n - m) % MOD);
	return 0;
}