#include <cstdio>
#include <cstring>

int cnt[6][6], cur[6][6];
char s[10];
int c[6];
int D;
int sto[6];
int n;

int val[6], used[6], last[6];

bool can(int dp = 0) {
	for (int i = 1; i < (1 << D); i ++) {
		int cs = 0, nv = 0, ne = 0;
		for (int j = 0; j < D; j ++) {
			if (i & (1 << j)) {
				sto[cs ++] = j;
				nv += c[j];
			}
		}
		for (int j = 0; j < cs; j ++) {
			for (int k = 0; k < cs; k ++) {
				ne += cnt[sto[j]][sto[k]];
			}
		}
		if (nv && nv <= ne) return 0;
	}
	return 1;
}

bool Find(int dp) {
	if (dp == n - 1) return 1;
	for (int i = 0; i < D; i ++) {
		for (int j = 0; j < D; j ++) {
			if (!cnt[i][j]) continue;
			if (c[i]) {
				cnt[i][j] --;
				c[i] --;
				if (can(dp)) {
					printf("%d %d\n", val[i] + used[i], last[j]);
					used[i] ++;
					if (Find(dp + 1)) return 1;
				}
				cnt[i][j] ++;
				c[i] ++;
			}
			if (c[j]) {
				cnt[i][j] --;
				c[j] --;
				if (can(dp)) {
					int x = val[j] + used[j];
					used[j] ++;
					printf("%d %d\n", last[i], x);
					if (Find(dp + 1)) return 1;
				}
				cnt[i][j] ++;
				c[j] ++;
			}
		}
	}
	return 0;
}

main() {
    scanf("%d", &n);
    val[0] = 1;
    for (int i = 1; i < 6; i ++) val[i] = val[i - 1] * 10;
    for (int i = 1; i <= n; i ++) {
    	sprintf(s, "%d", i);
		int x = strlen(s);
		c[x - 1] ++;last[x - 1] = i;
		if (D < x) D = x;
    }
    for (int i = 1; i < n; i ++) {
		scanf("%s", s);
		int x = strlen(s);
		scanf("%s", s);
		int y = strlen(s);
		cnt[x - 1][y - 1] ++;
    }
    if (!can()) return puts("-1");
    Find(0);
}