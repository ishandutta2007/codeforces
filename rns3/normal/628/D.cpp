#include <bits/stdc++.h>
using namespace std;
#define N 2020

typedef long long LL;

const LL mod = 1e9 + 7;

int len, m, d, ex[N];
char a[N], b[N];
LL f[N][N];

bool ok(char *s) {
	LL sum = 0;
	for (int i = 1; i <= len; i ++) {
		sum = (sum * 10 + (s[i] - '0')) % m;
		if (i % 2 == 0 && s[i] != '0' + d || i % 2 == 1 && s[i] == '0' + d) return 0;
	}
	return sum % m == 0;
}

LL calc(char *s) {
	LL rlt = 0;
	int x = 0;
	for (int i = 1; i <= len; i ++) {
		if (i % 2 == 0) {
			if (s[i] - '0' < d) return rlt;
            else {
				x = (x + ex[len-i] * d) % m;
				if (s[i] - '0' > d) {
					rlt = (rlt + f[len-i][(m-x)%m]) % mod;
					return rlt;
				}
            }
		}
		else {
			int st = (i == 1) ? 1 : 0, en = s[i] - '0';
            for (int j = st; j < en; j ++) {
				if (j == d) continue;
				int k = ((m - x - j * ex[len-i]) % m + m) % m;
				rlt = (rlt + f[len-i][k]) % mod;
            }
            if (en == d) return rlt;
            x = (x + ex[len-i] * en) % m;
		}
	}
	return rlt;
}

void prepare() {
	ex[0] = 1;
	for (int i = 1; i <= 2000; i ++) ex[i] = ex[i-1] * 10 % m;

	f[0][0] = 1;
    for (int i = 1; i <= len; i ++) {
		for (int j = 0; j <= 9; j ++) {
			if (len % 2 == i % 2 && j != d) {
				for (int k = 0; k < m; k ++) {
					int l = (k + j * ex[i-1]) % m;
					f[i][l] = (f[i][l] + f[i-1][k]) % mod;
				}
			}
			else if (len % 2 != i % 2 && j == d) {
				for (int k = 0; k < m; k ++) {
					int l = (k + j * ex[i-1]) % m;
					f[i][l] = (f[i][l] + f[i-1][k]) % mod;
				}
			}
		}
    }
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %s %s", &m, &d, a + 1, b + 1);
	len = strlen(a + 1);
	prepare();
	LL ans = calc(b) - calc(a);
	if (ok(b)) ans ++;
	ans = (ans % mod + mod) % mod;
	printf("%I64d\n", ans);
	return 0;
}