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

const int N = 3E3 + 10;

pii a[N];
int cnt[N], tcnt[N];
int mark[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a[i].nd, &a[i].st);
		++cnt[a[i].nd];
		if (a[i].nd == 1)
			--i, --n;
	}
	sort(a, a + n);

	ll ans = 1ll << 60;
	for (int K = 0; K <= n; ++K){
		int t = cnt[1];
		ll cost = 0;

		fill_n(mark, n, 0);
		copy_n(cnt + 1, m, tcnt + 1);
		for (int i = 0; i < n; ++i)
			if (tcnt[a[i].nd] > K)
				--tcnt[a[i].nd], mark[i] = true, cost += a[i].st, ++t;
		for (int i = 0; i < n && t <= K; ++i)
			if (!mark[i])
				cost += a[i].st, ++t;
		ans = min(ans, cost);
	}
	printf("%lld\n", ans);
	return 0;
}