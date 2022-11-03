#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E3 + 10;
const int MOD = 1E9 + 7;

int n;
char s[MAXN][MAXN];
double p[4][MAXN][MAXN];
int a[8][MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);

	double val[4] = {0., 0., log(2.), log(3.)};
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			s[i][j] -= '0';
			p[0][i][j] = p[0][i][j - 1] + val[s[i][j]];
			p[1][i][j] = p[1][i - 1][j - 1] + val[s[i][j]];
			p[2][i][j] = p[2][i - 1][j] + val[s[i][j]];
			p[3][i][j] = p[3][i - 1][j + 1] + val[s[i][j]];
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (s[i][j]){
				a[0][i][j] = a[0][i][j - 1] + 1;
				a[1][i][j] = a[1][i - 1][j - 1] + 1;
				a[2][i][j] = a[2][i - 1][j] + 1;
				a[3][i][j] = a[3][i - 1][j + 1] + 1;
			}
			else
				a[0][i][j] = a[1][i][j] = a[2][i][j] = a[3][i][j] = 0;
	for (int i = n; i >= 1; --i)
		for (int j = n; j >= 1; --j)
			if (s[i][j]){
				a[4][i][j] = a[4][i][j + 1] + 1;
				a[5][i][j] = a[5][i + 1][j + 1] + 1;
				a[6][i][j] = a[6][i + 1][j] + 1;
				a[7][i][j] = a[7][i + 1][j - 1] + 1;
			}
			else
				a[4][i][j] = a[5][i][j] = a[6][i][j] = a[7][i][j] = 0;
	double ans = -1.0;
	int x = 0, y = 0, z = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			if (!s[i][j])
				continue;

			int l = min(min(a[0][i][j], a[2][i][j]), min(a[4][i][j], a[6][i][j]));
			double res = p[0][i][j + l - 1] - p[0][i][j - l] + p[2][i + l - 1][j] - p[2][i - l][j] - val[s[i][j]];
			if (ans < res)
				ans = res, x = i, y = j, z = l;
			l = min(min(a[1][i][j], a[3][i][j]), min(a[5][i][j], a[7][i][j]));
			res = p[1][i + l - 1][j + l - 1] - p[1][i - l][j - l] + p[3][i + l - 1][j - l + 1] - p[3][i - l][j + l] - val[s[i][j]];
			if (ans < res)
				ans = res, x = i, y = j, z = -l;
		}
	if (ans < 0.)
		puts("0");
	else if (z > 0){
		unsigned ans = s[x][y];
		for (int i = -z + 1; i < z; ++i)
			if (i){
				ans = ans * s[x][y + i] % MOD;
				ans = ans * s[x + i][y] % MOD;
			}
		printf("%u\n", ans);
	}
	else{
		unsigned ans = s[x][y];
		for (int i = -z - 1; i > z; --i)
			if (i){
				ans = ans * s[x + i][y + i] % MOD;
				ans = ans * s[x + i][y - i] % MOD;
			}
		printf("%u\n", ans);
	}
	return 0;
}