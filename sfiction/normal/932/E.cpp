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

const int NK = 5E3 + 10;
const ll MOD = 1E9 + 7, INV2 = (MOD + 1) / 2;

int n, K;
ll a[NK], s[NK];

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

int main(){
	scanf("%lld%d", &n, &K);
	a[1] = n * modExp(2, n - 1) % MOD;
	for (int i = 2; i <= K; ++i)
		a[i] = a[i - 1] * (n - i + 1) % MOD * INV2 % MOD;
	s[1] = 1;
	for (int i = 2; i <= K; ++i){
		for (int j = i; j > 1; --j)
			s[j] = (s[j - 1] + s[j] * j) % MOD, eput(i, j, s[j]);
	}
	ll ans = 0;
	for (int i = 1; i <= K; ++i)
		ans = (ans + s[i] * a[i]) % MOD;
	printf("%lld\n", ans);

	return 0;
}