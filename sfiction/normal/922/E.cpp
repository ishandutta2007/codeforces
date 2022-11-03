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

const int N = 1E3 + 10, M = 1E4 + 10;

int n, m;
ll W, B, X;
int c[N];
ll cost[M], f[M];

int main(){
	scanf("%d%lld%lld%lld", &n, &W, &B, &X);
	m = 0;
	for (int i = 1; i <= n; ++i){
		scanf("%d", c + i);
		m += c[i];
	}
	for (int i = 1; i <= n; ++i)
		scanf("%lld", cost + i);

	f[0] = W;
	fill_n(f + 1, m, -1);
	for (int i = 1; i <= n; ++i){
		// [j - c[i], j - 1]
		typedef pair<int, ll> pil;
		static pil que[M];
		int l = 0, r = 1;
		que[0] = pil(0, f[0]);
		ll limit = W + B;
		for (int j = 1; j <= m; ++j){
			eput(l, r);
			eput(vector<pil>(que + l, que + r));
			if (que[l].st < j - c[i])
				++l;
			ll t = f[j] + cost[i] * j;
			for (; l < r && que[r - 1].nd < t; --r);
			que[r++] = pil(j, t);

			if (que[l].nd - cost[i] * j >= 0)
				f[j] = min(limit, que[l].nd - cost[i] * j + X);
			limit += B;

			eput(i, j, f[j]);
		}
	}

	int ans = m;
	for (; ans > 0 && f[ans] == -1; --ans);
	printf("%d\n", ans);

	return 0;
}