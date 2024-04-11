#include <bits/stdc++.h>
using namespace std;

#define N 500200

typedef long long ll;
int t, num, n, m, last;
int nxt[N<<1][26], link[N<<1], dp[N<<1], cnt[N<<1], ord[N<<1];
ll occur[N<<1];
string s[N];

void init() {
	m = 0;
	last = ++ m;
	memset(nxt[last], 0, sizeof nxt[last]);
	occur[last] = 0;
	dp[last] = 0;
}

void extend(int c) {
	if (nxt[last][c] && dp[nxt[last][c]] == dp[last] + 1) {
		last = nxt[last][c]; return;
	}
	int x = last, y = last = ++ m;
	memset(nxt[y], 0, sizeof nxt[y]);
	occur[y] = 0;
	dp[y] = dp[x] + 1;
	while (x && !nxt[x][c]) nxt[x][c] = y, x = link[x];
	if (!x) link[y] = 1;
	else {
		int z = nxt[x][c];
		if (dp[z] == dp[x] + 1) link[y] = z;
		else {
			int u = ++ m;
			memcpy(nxt[u], nxt[z], sizeof nxt[u]);
			link[u] = link[z], link[z] = link[y] = u;
			occur[u] = 0;
			dp[u] = dp[x] + 1;
			while (x && nxt[x][c] == z) nxt[x][c] = u, x = link[x];
		}
	}
}

int c[N];

int main() {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i ++) {
        char tmp[N];
        scanf("%s", tmp);
        s[i] = tmp;
    }
    for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i ++) {
        last = 1;
        for (int j = 0; j < s[i].size(); j ++) extend(s[i][j] - 'a'), occur[last] += c[i];
    }
    for (int i = 1; i <= m; i ++) cnt[i] = 0;
    for (int i = 1; i <= m; i ++) cnt[dp[i]] ++;
    for (int i = 1; i <= m; i ++) cnt[i] += cnt[i-1];
    for (int i = 1; i <= m; i ++) ord[cnt[dp[i]]--] = i;
    for (int i = m; i >= 1; i --) occur[link[ord[i]]] += occur[ord[i]];
    ll ans = 0;
    for (int i = 1; i <= m; i ++) {
        ans = max(ans, dp[i] * occur[i]);
    }
    printf("%I64d\n", ans);
	return 0;
}