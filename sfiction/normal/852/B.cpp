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

const int MAXN = 1E6 + 10, M = 100;
const ll MOD = 1E9 + 7;

struct Mat{
	ll a[M][M];
}c[3];

int n, L, m;
int a[3][MAXN];
int cnt[M];

Mat operator *(const Mat &l, const Mat &r){
	Mat ret;
	for (int i = 0; i < m; ++i){
		fill_n(ret.a[i], m, 0);
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < m; ++j)
				ret.a[i][j] = (ret.a[i][j] + l.a[i][k] * r.a[k][j]) % MOD;
	}
	return ret;
}

int main(){
	scanf("%d%d%d", &n, &L, &m);
	for (int j = 0; j < 3; ++j)
		for (int i = 0; i < n; ++i)
			scanf("%d", a[j] + i);
	for (int i = 0; i < n; ++i)
		a[2][i] += a[1][i];

	for (int j = 0; j < 3; ++j){
		fill_n(cnt, m, 0);
		for (int i = 0; i < n; ++i)
			++cnt[a[j][i] % m];
		for (int i = 0; i < m; ++i)
			for (int k = 0; k < m; ++k)
				c[j].a[i][k] = cnt[(i - k + m) % m];
	}
	for (int tn = L - 2; tn > 0; tn >>= 1, c[1] = c[1] * c[1])
		if (tn & 1)
			c[0] = c[1] * c[0];
	c[0] = c[2] * c[0];
	
	printf("%d\n", (int)c[0].a[0][0]);
	return 0;
}