#include <bits/stdc++.h>
using namespace std;

#define N 50005

int n, q, a[N];

vector <int> v[N];
int dp[N];

int tot, rt;
int nxt[3005][2];
int make_node() {
	tot ++;
	nxt[tot][0] = nxt[tot][1] = 0;
	return tot;
}
void init() {
	tot = -1;
	make_node();
	rt = make_node();
}
void insert(int val) {
	int nd = rt, x;
	for (int i = 0; i < 16; i ++) {
		x = (val >> 15 - i) & 1;
		if (!nxt[nd][x]) nxt[nd][x] = make_node();
		nd = nxt[nd][x];
	}
}
int query(int val) {
	int nd = rt, x, res = 0;
	for (int i = 0; i < 16; i ++) {
		x = (val >> 15 - i) & 1;
		if (nxt[nd][x^1]) nd = nxt[nd][x^1], res += 1 << 15 - i;
		else nd = nxt[nd][x];
	}
	return res;
}

int c[N][256], pp[N], p[N];

void dfs(int k, int pa) {
    dp[k] = dp[pa]+ 1, p[k] = pa;
    if (dp[k] >= 256) {
        init();
        int now = k;
        for (int i = 0; i < 256; i ++) {
            insert(a[now]^i);
            now = p[now];
        }
        pp[k] = now;
        int t = 0;
        for (int i = 0; i < 256; i ++) {
            c[k][i] = query(t);
			t += 256;
        }
    }
    for (auto x : v[k]) {
        if (x == pa) continue;
        dfs(x, k);
    }
	return;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int x, y;
    for (int i = 1; i < n; i ++) {
        scanf("%d %d", &x, &y);
		v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    while (q --) {
		scanf("%d %d", &x, &y);
        int ans = 0, now = 0;
        for (int i = 0; dp[y] - dp[x] >= 255; i ++) {
            ans = max(c[y][i], ans);
            now += 256;
            y = pp[y];
        }
        while (dp[x] <= dp[y]) {
            ans = max(a[y]^now, ans);
            now ++;
            y = p[y];
        }
        printf("%d\n", ans);
    }
    return 0;
}