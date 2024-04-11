#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, le[N], ri[N];
char s[N];

int tot, ord[N];

void dfs(int u) {
	while (le[u]) {
		le[u] --, ri[u-1] --;
		dfs(u - 1);
	}
	while (ri[u]) {
		ri[u] --, le[u+1] --;
		dfs(u + 1);
	}
	ord[tot++] = u;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int m = 2 * n + 5;
		for (int i = 1; i <= m; i ++) le[i] = ri[i] = 0;
		int sum = n + 2; tot = 0;
		for (int i = 1; i <= n; i ++) {
			if (s[i] == '1') ri[sum] ++, le[++sum] ++;
			else le[sum] ++, ri[--sum] ++;
		}
		dfs(n + 2);
		assert(tot == n + 1);
		reverse(ord, ord + tot);
		for (int i = 1; i <= n; i ++) putchar('0' + (ord[i] == ord[i-1] + 1));
		puts("");
    }

    return 0;
}