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

int n, m;
int l[N];
vector<int> a[N];
vector<ll> b[N], c[N];

ll calc(int u, ll h){
	int x = lower_bound(all(b[u]), h) - b[u].begin();
	return x == 0 ? 0 : x * h - c[u][x - 1];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; ++i){
		int x;
		scanf("%d", &x);
		l[i] = x;
		a[i >> 1].push_back(x);
	}
	for (int i = n; i >= 1; --i){
		b[i].push_back(0);
		for (int j = 0; j < a[i].size(); ++j){
			int v = i << 1 | j, d = a[i][j];
			for (auto &x: b[v])
				b[i].push_back(x + d);
		}
		sort(all(b[i]));
		c[i].resize(b[i].size());
		copy(all(b[i]), c[i].begin());
		partial_sum(all(c[i]), c[i].begin());
	}
	for (int i = 0; i < m; ++i){
		int u, h;
		scanf("%d%d", &u, &h);
		ll ans = calc(u, h);
		for (; u > 1; h -= l[u], u >>= 1)
			ans += calc(u >> 1, h - l[u]) - calc(u, h - l[u] * 2);
		printf("%lld\n", ans);
	}
	return 0;
}