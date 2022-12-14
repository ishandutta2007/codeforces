#include <bits/stdc++.h>
using namespace std;

#define N 1515

int n, f[30][N], T, id[30][N], cnt[30];
char s[N];

int main() {
	scanf("%d\n", &n);
	gets(s + 1);
	for (int i = 1, j; i <= n; i ++) {
		j = s[i] - 'a';
        id[j][++cnt[j]] = i;
	}
    for (int j = 0; j < 26; j ++) {
        if (!cnt[j]) continue;
        for (int d = 0, now; d <= cnt[j] - 1; d ++) {
			now = N;
			for (int i = 1; i <= cnt[j] - d; i ++) now = min(now, id[j][i+d] - id[j][i]);
			f[j][d] = now;
        }
    }
    scanf("%d", &T);
    int m, st, en, mid, j;
    char c;
    while (T --)  {
		scanf("%d %c", &m, &c);
		j = c - 'a';
		st = m;
		en = n + 1;
        while (en - st > 1) {
			mid = (en + st + 1) / 2;
            if (mid <= cnt[j] + m && f[j][mid-m-1] <= mid - 1) st = mid;
            else en = mid;
        }
        printf("%d\n", st);
    }
	return 0;
}