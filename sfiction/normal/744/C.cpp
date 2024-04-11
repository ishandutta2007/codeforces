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

const int MAXN = 16;
const int INF = 1 << 30;

int n;
int type[MAXN];
int r[MAXN], b[MAXN];
int f[1 << MAXN][MAXN * MAXN];

int main(){
	scanf("%d", &n);
	char s[5];
	for (int i = 0; i < n; ++i){
		scanf("%s%d%d", s, r + i, b + i);
		type[i] = s[0] == 'B';
	}

	int n0 = 1 << n, n2 = n * (n + 1) >> 1;
	for (int i = 0; i < n0; ++i)
		fill_n(f[i], n2 + 1, -INF);
	f[0][0] = 0;
	for (int i = 0; i < n0 - 1; ++i){
		int c[2] = {0, 0};
		for (int j = 0; j < n; ++j)
			c[type[j]] += i >> j & 1;
		for (int mask, j = 0; j < n; ++j){
			if ((mask = i ^ 1 << j) <= i)
				continue;

			int cr = min(c[0], r[j]), cb = min(c[1], b[j]);
			for (int k = 0; k <= n2; ++k)
				f[mask][k + cr] = max(f[mask][k + cr], f[i][k] + cb);
		}
	}
	int c[2] = {accumulate(r, r + n, 0), accumulate(b, b + n, 0)};
	int ans = INF;
	for (int i = 0; i <= n2; ++i)
		ans = min(ans, max(c[0] - i, c[1] - f[n0 - 1][i]));
	printf("%d\n", n + ans);
	return 0;
}