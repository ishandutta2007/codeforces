#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E3 + 10, MAXM = 1E5 + 10;
const int MOD = 1E9 + 7;

int n, m;
char s[MAXM];

int f[MAXN][MAXN];

int main(){
	scanf("%d%d", &n, &m);
	if (n & 1){
		puts("0");
		return 0;
	}
	scanf("%s", s);
	int left = 0, right = 0, tot = 0;
	for (int i = 0; i < m; ++i){
		tot += s[i] == ')' ? 1 : -1;
		right = max(right, tot);
	}
	tot = 0;
	for (int i = m - 1; i >= 0; --i){
		tot += s[i] == '(' ? 1 : -1;
		left = max(left, tot);
	}
	tot += m - tot >> 1;
	n -= m;
	f[0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = i >> 1; j >= 0; --j){
			f[i][j] %= MOD;
			f[i + 1][j] += f[i][j];
			f[i + 1][j + 1] += f[i][j];
		}
	for (int j = n >> 1; j >= 0; --j)
		f[n][j] %= MOD;
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = min(i - right, i - right >> 1), k = (n + m) / 2 - tot - (i - j); j >= 0 && k >= 0; --j, --k)
			if (k * 2 + left <= n - i)
				ans = (ans + f[i][j] * (long long)f[n - i][k]) % MOD;
	printf("%d\n", ans);
	return 0;
}