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

const int MAXN = 1E6 + 1E3;

ll inv[MAXN], fac[MAXN], facinv[MAXN];

ll modExp(ll e, ll n, ll m){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

void getInv(int n, ll m){
	inv[0] = 0, inv[1] = 1;
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= n; ++i){
		inv[i] = inv[m % i] * (m - m / i) % m;
		fac[i] = fac[i - 1] * i % m;
		facinv[i] = facinv[i - 1] * inv[i] % m;
	}
}

ll C(int n, int m, int P){
	return n < m || m < 0 ? 0 : fac[n] * facinv[m] % P * facinv[n - m] % P;
}

int main(){
	int n, m, a, Q;
	scanf("%d%d%d%d", &n, &m, &a, &Q);
	int P = 1;
	for (ll t = a; t > 1; t = t * a % Q, ++P);
	getInv(P, P);

	ll s = 0;
	vector<int> ans;
	for (int i = 0; i < n; ++i){
		if (i <= m)
			s = (s + C(m, i, P)) % P;
		ans.emplace_back(modExp(a, s, Q));
	}
	for (int i = n - 1; i >= 0; --i)
		printf("%d%c", ans[i], "\n "[i > 0]);

	return 0;
}