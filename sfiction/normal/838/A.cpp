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

const int MAXN = 2500 + 10;

int n, m;
int a[MAXN][MAXN];
char s[MAXN];
int isnp[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j)
			a[i][j] = a[i][j - 1] + (s[j] - '0');
		for (int j = 1; j <= m; ++j)
			a[i][j] += a[i - 1][j];
	}

	int n0 = max(n, m);
	int ans = n * m;
	for (int i = 2; i <= n0; ++i){
		if (isnp[i])
			continue;
		for (int j = i * i; j <= n0; j += i)
			isnp[j] = true;
		int i2 = i * i;
		int tot = 0;
		for (int x = 0; x < n; x += i)
			for (int y = 0; y < m; y += i){
				int xm = min(n, x + i), ym = min(m, y + i);
				int t = a[xm][ym] - a[xm][y] - a[x][ym] + a[x][y];
				tot += min(t, i2 - t);
			}
		eput(i, tot);
		ans = min(ans, tot);
	}
	printf("%d\n", ans);
	return 0;
}