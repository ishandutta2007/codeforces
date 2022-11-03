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

const int D = 19, N = 1E6 + 10 + D, MOD = 1E9 + 7;

int f[N][D + 1], e[N];

int np, md[N], prime[N];
bool isnp[N + 1];

void getPrime(int n = N){
	np = 0, isnp[0] = isnp[1] = true;
	for (int i = 2; i <= n; ++i){
		if (!isnp[i])
			md[i] = i, prime[np++] = i;
		for (int j = 0; j < np && prime[j] <= n / i; ++j){
			int t = prime[j] * i;
			md[t] = prime[j];
			isnp[t] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}

int main(){
	for (int i = 0; i <= D; ++i){
		f[i][0] = f[i][i] = 1;
		for (int j = 1; j < i; ++j)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
	}
	for (int i = D + 1; i < N; ++i){
		f[i][0] = 1;
		for (int j = 1; j <= D; ++j)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
	}
	e[0] = 1;
	for (int i = 1; i < N; ++i)
		e[i] = e[i - 1] * 2 % MOD;
	getPrime();

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = e[y - 1];
		for (; x > 1; ){
			int t = md[x], cnt = 0;
			for (; md[x] == t; x /= t)
				++cnt;
			ans = ans * f[cnt + y - 1][cnt] % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}