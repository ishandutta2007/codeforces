#include <bits/stdc++.h>
using namespace std;

#define N 7010

int rr, mm, r[N], m[N], n, f[N], g[N], flag;
char ans[][7] = {"Lose", "Loop", "Win"};

int func(int k) {
	return (k + n * n - 1) % n + 1;
}

int main() {//freopen("9.in", "r", stdin);freopen("9.out", "w", stdout);
	scanf("%d", &n);
	scanf("%d", &rr);
	for (int i = 1; i <= rr; i ++) scanf("%d", &r[i]);
	scanf("%d", &mm);
	for (int i = 1; i <= mm; i ++) scanf("%d", &m[i]);
	memset(f, 0, sizeof f);
	memset(g, 0, sizeof g);
	f[1] = g[1] = -1;
    for (int i = 1; i <= rr; i ++) f[func(1-r[i])] = 1;
    for (int i = 1; i <= mm; i ++) g[func(1-m[i])] = 1;
    if (rr >= mm) {
		flag = 1;
		while (flag) {
			flag = 0;
			for (int j = 0; j > 1 - n; j --) if (g[func(j)] == 0) {
				int tag = 1;
				for (int i = 1; i <= mm && tag; i ++) if (f[func(j+m[i])] <= 0) tag = 0;
				if (tag) {
					flag = 1;
					g[func(j)] = -1;
					for (int i = 1; i <= rr; i ++) if (f[func(j-r[i])] == 0) f[func(j-r[i])] = 1;
				}
			}
		}
    }
    if (mm >= rr) {
		flag = 1;
		while (flag) {
			flag = 0;
			for (int j = 0; j > 1 - n; j --) if (f[func(j)] == 0) {
				int tag = 1;
				for (int i = 1; i <= rr && tag; i ++) if (g[func(j+r[i])] <= 0) tag = 0;
				if (tag) {
					flag = 1;
					f[func(j)] = -1;
					for (int i = 1; i <= mm; i ++) if (g[func(j-m[i])] == 0) g[func(j-m[i])] = 1;
				}
			}
		}
    }
	for (int i = 2; i < n; i ++) printf("%s ", ans[f[i]+1]);puts(ans[f[n]+1]);
	for (int i = 2; i < n; i ++) printf("%s ", ans[g[i]+1]);puts(ans[g[n]+1]);
	return 0;
}