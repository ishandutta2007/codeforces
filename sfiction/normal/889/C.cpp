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
const ll MOD = 1E9 + 7;

int n, K;
ll inv[N], fac[N], facinv[N];
ll f[N], g[N];

void getPrime(int n = N - 1, ll m = MOD){
	inv[0] = 0, inv[1] = 1;
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= n; ++i){
		inv[i] = inv[m % i] * (m - m / i) % m;
		fac[i] = fac[i - 1] * i % m;
		facinv[i] = facinv[i - 1] * inv[i] % m;
	}
}

int main(){
	getPrime();

	scanf("%d%d", &n, &K);
	if (K + 1 >= n){
		puts("0");
		return 0;
	}
	for (int i = K + 2; i <= n; ++i){
		f[i] = ((i - K - 1) + g[i - 1] - g[i - K - 1] + MOD) % MOD;
		f[i] = f[i] * fac[i - 2] % MOD;
		g[i] = (g[i - 1] + f[i] * facinv[i - 1]) % MOD;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = (ans + f[i] * facinv[i - 1]) % MOD;
	printf("%lld\n", ans * fac[n - 1] % MOD);
	return 0;
}