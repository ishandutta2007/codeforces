#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int K = 10;

#define N 707

int cou[N][K][N], E[N];

void prep_cou() {
	E[0] = 1;
	for (int i = 1; i < N; i ++) E[i] = 10ll * E[i-1] % mod;
	for (int k = 0; k < K; k ++) cou[0][k][0] = 1;
	for (int m = 1; m < N; m ++) {
		for (int k = 0; k < K; k ++) {
			cou[m][k][0] = E[m];
			for (int i = 1; i <= m; i ++) {
				int now = 0;
				for (int j = 0; j < K; j ++) {
					if (j >= k) now = (now + cou[m-1][k][i-1]) % mod;
					else now = (now + cou[m-1][k][i]) % mod;
				}
				cou[m][k][i] = now;
			}
		}
	}
}

int f[N][K], n;

int func(int sz, int r, int gas) {
	if (gas > sz) return 0;
	if (gas <= 0) return E[sz];
	return cou[sz][r][gas];
}

int cnt[K];

void update(int sz) {
	int tot = 0;
	for (int r = 9; r >= 0; r --) {
		tot += cnt[r];
		for (int i = 0; i < n; i ++) {
			f[i][r] = (f[i][r] + func(sz, r, i + 1 - tot)) % mod;
		}
	}
}

char s[N];

int origin() {
	sort(s, s + n);
	int rlt = 0;
	for (int i = 0; i < n; i ++) {
		rlt = (10ll * rlt + (int)(s[i] - '0')) % mod;
	}
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	prep_cou();
	while (gets(s) > 0) {
		n = strlen(s);
		memset(f, 0, sizeof f);
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < n; j ++) {
			int bi = s[j] - '0';
			for (int ci = 0; ci < bi; ci ++) {
				cnt[ci] ++;
				update(n - j - 1);
				cnt[ci] --;
			}
			cnt[bi] ++;
		}
		int ans = origin();
		for (int i = 0; i < n; i ++) {
			int now = 0;
			for (int k = 1; k < K; k ++) now = (now + f[i][k]) % mod;
			ans = (ans + 1ll * now * E[i]) % mod;
		}
		printf("%d\n", ans);
		return 0;
	}

	return 0;
}