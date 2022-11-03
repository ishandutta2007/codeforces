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

const int N = 1E5 + 10, D = 20;
const ll MOD = 1E9 + 7;

int a[N];
int b[N][D], c[N];

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

int check(int b[], int x){
	for (int j = D - 1; j >= 0; --j)
		if (x & (1 << j))
			x ^= b[j];
	return x;
}

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		copy_n(b[i - 1], D, b[i]);
		c[i] = c[i - 1];

		if (a[i] == 0)
			continue;
		a[i] = check(b[i], a[i]);
		if (a[i]){
			b[i][31 - __builtin_clz(a[i])] = a[i];
			++c[i];
		}
	}
	for (int i = 0; i < q; ++i){
		int r, x;
		scanf("%d%d", &r, &x);
		int ret = check(b[r], x);
		printf("%lld\n", ret ? 0 : modExp(2, r - c[r]));
	}
	return 0;
}