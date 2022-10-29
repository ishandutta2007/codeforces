#include <iostream>
#include <complex>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

#ifdef WIN32
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif

#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define forn(i,a,b) for(int i = (a); i < (b); ++i)

#define pi M_PI

#define maxn 2050

const ll MD = 1000000007;
ll inc[maxn][maxn];
ll sum[maxn][maxn];
int n, m;
ll inc_big[maxn][maxn][2];
ll cur_sum[maxn], cur_sum1[maxn];

int make_inc(int n, int m) {
	forn(i, 2, m + 1) {
		inc[1][i] = 1LL;
		sum[1][i] = sum[1][i - 1] + inc[1][i];
	}
	forn(x, 2, n + 1) {
		forn(y, 2, m + 1) {
			inc[x][y] = (inc[x][y - 1] + sum[x - 1][y - 1] + inc[x - 1][y - 1]) % MD;
			if ((sum[x][y] = sum[x][y - 1] + inc[x][y]) >= MD) sum[x][y] -= MD;
		}
	}
	return 0;
}

int make_big(int n, int m) {
	forn(i, 0, n + 1)
		forn(j, 0, m + 1)
			sum[i][j] = 0;
	forn(y, 2, m + 1) {
		inc_big[1][y][0] = 1LL; inc_big[1][y][1] = 0LL;
		sum[1][y] = (sum[1][y - 1] + inc_big[1][y][0] + inc_big[1][y][1]) % MD;
	}
	forn(x, 2, n + 1) {
		forn(y, 2, m + 1) {
			if ((inc_big[x][y][1] = inc_big[x - 1][y][1] + inc_big[x - 1][y][0]) >= MD) inc_big[x][y][1] -= MD;
			inc_big[x][y][0] = (inc_big[x][y - 1][0] + sum[x - 1][y - 1] + inc_big[x - 1][y - 1][0] + inc_big[x - 1][y - 1][1]) % MD;
			sum[x][y] = (sum[x][y - 1] + inc_big[x][y][0] + inc_big[x][y][1]) % MD;
		}
	}
	return 0;
}

ll make_shift(const int &m) {
	ll ans = 0LL;
	forn(i, 0, n + 1)
		cur_sum[i] = cur_sum1[i] = 0LL;
	for (int i = 1; i <= n; ++i) {
		cur_sum[i] = (cur_sum[i - 1] + inc_big[i][m][0]) % MD;
		cur_sum1[i] = (cur_sum1[i - 1] + inc_big[i][m][1] + inc_big[i][m][0]) % MD;
	}
	for (int i = 1; i <= n; ++i)
		ans += (cur_sum[i] * cur_sum1[n - i + 1]) % MD;
	return ans % MD;
}

int main() {
	scanf("%d%d", &n, &m);
	make_inc(n, m);
	make_big(n, m);
	ll res = 0LL;
	forn(i, 2, m + 1)
		res += (m - i + 1) * make_shift(i) % MD;
	printf(LLD"\n", res % MD);
	return 0;
}