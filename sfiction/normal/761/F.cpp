#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E3 + 10, SIGMA = 26, MAXM = 3E5 + 10;

int n, m, q;
char s[MAXN][MAXN];
ll sc[SIGMA][MAXN][MAXN];
ll sd[MAXN][MAXN];
int x0[MAXM], y0[MAXM], x1[MAXM], y1[MAXM];
int c[MAXM];

void buildSum(ll a[][MAXN], int n, int m){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j)
			a[i][j] += a[i][j - 1];
		for (int j = 1; j <= m; ++j)
			a[i][j] += a[i - 1][j];
	}
}

ll getSum(ll A[][MAXN], int a, int b, int c, int d){
	return A[c][d] - A[c][b - 1] - A[a - 1][d] + A[a - 1][b - 1];
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i){
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; ++j)
			s[i][j] -= 'a';
	}
	char chr[5];
	for (int i = 0; i < q; ++i){
		scanf("%d%d%d%d%s", x0 + i, y0 + i, x1 + i, y1 + i, chr);
		c[i] = chr[0] - 'a';
		++sc[c[i]][x0[i]][y0[i]];
		--sc[c[i]][x1[i] + 1][y0[i]];
		--sc[c[i]][x0[i]][y1[i] + 1];
		++sc[c[i]][x1[i] + 1][y1[i] + 1];
	}
	for (int k = 0; k < SIGMA; ++k)
		buildSum(sc[k], n, m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j){
			ll sum = q;
			for (int k = 0; k < SIGMA; ++k)
				sum -= sc[k][i][j];
			sc[s[i][j]][i][j] += sum;
			for (int k = 0; k < s[i][j]; ++k)
				sd[i][j] += (s[i][j] - k) * sc[k][i][j];
			for (int k = s[i][j] + 1; k < SIGMA; ++k)
				sd[i][j] += (k - s[i][j]) * sc[k][i][j];
		}
	for (int k = 0; k < SIGMA; ++k)
		buildSum(sc[k], n, m);
	buildSum(sd, n, m);
	ll ans = -1;
	for (int i = 0; i < q; ++i){
		ll tot = sd[n][m];
		tot -= getSum(sd, x0[i], y0[i], x1[i], y1[i]);
		for (int k = 0; k < c[i]; ++k)
			tot += (c[i] - k) * getSum(sc[k], x0[i], y0[i], x1[i], y1[i]);
		for (int k = c[i] + 1; k < SIGMA; ++k)
			tot += (k - c[i]) * getSum(sc[k], x0[i], y0[i], x1[i], y1[i]);
		if (ans == -1 || ans > tot)
			ans = tot;
	}
	printf("%lld\n", ans);
	return 0;
}