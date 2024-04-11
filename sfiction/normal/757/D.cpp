#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 80, MAXD = 20, MAXM = 1 << MAXD;
const int MOD = 1E9 + 7;

int n;
char s[MAXN];
int f[MAXN][MAXM];

void update(int &x, int y){
	if ((x += y) >= MOD)
		x -= MOD;
}

int main(){
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i)
		s[i] -= '0';
	int m = 0;
	for (int t = 0; (t + 32 - __builtin_clz(m + 1)) <= n; ++m)
		t += 32 - __builtin_clz(m + 1);
	int m0 = 1 << m;

	f[n][0] = 1;
	int ans = 0;
	for (int i = n - 1; i >= 0; --i){
		if (s[i] == 0)
			copy_n(f[i + 1], m0, f[i]);
		else{
			f[i][0] = 1;
			int num = 0;
			for (int k = i + 1; k <= n; ++k){
				if ((num = num << 1 | s[k - 1]) > m)
					break;
				for (int t = 1 << num - 1, j = m0 - 1; j >= 0; --j)
					update(f[i][j | t], f[k][j]);
			}
		}
		for (int j = 1; j <= m; ++j)
			update(ans, f[i][(1 << j) - 1]);
	}
	printf("%d\n", ans);
	return 0;
}