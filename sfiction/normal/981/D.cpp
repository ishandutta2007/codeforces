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

const int N = 5E1 + 10;

int n, K;
ll a[N], s[N];
int f[N][N];

bool check(ll L){
	f[0][0] = true;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= K; ++j){
			f[i][j] = false;
			for (int k = j - 1; k < i; ++k)
				f[i][j] |= f[k][j - 1] && (s[i] - s[k] & L) == L;
		}
	return f[n][K];
}

int main(){
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	partial_sum(a + 1, a + n + 1, s + 1);

	ll ans = 0;
	for (int i = 63; i >= 0; --i){
		if (check(ans | 1ll << i))
			ans |= 1ll << i;
	}
	printf("%lld\n", ans);
	return 0;
}