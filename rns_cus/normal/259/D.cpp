#include <bits/stdc++.h>
using namespace std;
#define N 22
#define mod 1000000007

typedef long long LL;

int n, m, a[N], id[N];
LL f[N][N], g[N], now[N], ans;

int main() {
//	freopen("d.in", "r", stdin);
	f[0][0] = 1;
	for (int i = 1; i <= 9; i ++) {
		f[i][0] = f[i-1][0] * 8;
		for (int j = 1; j <= i; j ++) f[i][j] = f[i-1][j] * 8 + f[i-1][j-1] * 2;
	}
	scanf("%d", &m);
//	srand(time(NULL));
//	m = rand() * rand() + 1;;
//	printf("%d\n", m); int mm = m
	while (m) a[++n] = m % 10, m /= 10;
	int x = 0;
	for (int i = n; i >= 1; i --) {
		for (int j = 0; j < a[i]; j ++) {
			if (j == 4 || j == 7) {
				for (int k = 0; k <= 9; k ++) g[x+1+k] += f[i-1][k];
			}
			else {
				for (int k = 0; k <= 9; k ++) g[x+k] += f[i-1][k];
			}
		}
		if (a[i] == 4 || a[i] == 7) x ++;
	}
	g[x] ++;
	g[0] --;
	int sum = 0;
	for (int i = 0; i <= 9; i ++) sum += g[i];
//	printf("%d\n", sum);
//	assert(mm == sum);
//	for (int i = 0; i <= 9; i ++) printf("%d ", g[i]); puts("");
	for (id[1] = 0; id[1] <= 9; id[1] ++) {
		for (id[2] = 0; id[2] <= 9; id[2] ++) {
			for (id[3] = 0; id[3] <= 9; id[3] ++) {
				for (id[4] = 0; id[4] <= 9; id[4] ++) {
					for (id[5] = 0; id[5] <= 9; id[5] ++) {
						for (id[6] = 0; id[6] <= 9; id[6] ++) {
							for (id[7] = id[1] + id[2] + id[3] + id[4] + id[5] + id[6] + 1; id[7] <= 9; id[7] ++) {
								for (int k = 0; k <= 9; k ++) now[k] = g[k];
								LL rlt = 1;
								for (int k = 1; k <= 7; k ++) {
									if (!now[id[k]]) {
										rlt = 0; break;
									}
									rlt = rlt * now[id[k]] % mod;
									now[id[k]] --;
								}
								ans = (ans + rlt) % mod;
							}
						}
					}
				}
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}