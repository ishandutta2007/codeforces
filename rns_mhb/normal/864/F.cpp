#include <bits/stdc++.h>
using namespace std;
#define N 3005
#define M 20
#define K 400005
#define pb push_back

int dp[N][M], p[N], dep[N];
bool ok[N];
int vis[N], dt[N], low[N], T;
int ans[K];

int n, m, Q;
vector <int> v[N];

struct myquery {
	int s, f, k, id;
	bool operator < (const myquery &a) const {
        return s < a.s;
	}
	void input(int i) {
        scanf("%d %d %d", &s, &f, &k);
        id = i;
	}
} q[K];

void init() {
	for (int i = 1; i <= n; i ++) {
		dt[i] = vis[i] = 0;
		p[i] = -1; ok[i] = 0;
		dep[i] = 0;
	}
	T = 0;
}

void dfs(int k, int pa = 0, bool f = 0) {
    vis[k] = 1;
    if (!f) p[k] = pa;
    dt[k] = ++ T; low[k] = ++ T;
    for (int i = 0; i < v[k].size(); i ++) {
        if (vis[v[k][i]] == 2) continue;
        if (vis[v[k][i]] == 1) {
            low[k] = min(low[k], dt[v[k][i]]);
        }
        else {
            bool g = (f || (low[k] <= dt[k]));
            dep[v[k][i]] = dep[k] + 1;
			dfs(v[k][i], k, g);
			low[k] = min(low[k], low[v[k][i]]);
        }
    }
    vis[k] = 2;
    return;
}

void build() {
    for (int i = 1; i <= n; i ++) dp[i][0] = p[i];
    for (int j = 1; j < 13; j ++) {
        for (int i = 1; i <= n; i ++) {
			if (dp[i][j-1] > 0) dp[i][j] = dp[dp[i][j-1]][j-1];
            else dp[i][j] = -1;
        }
    }
}

int query(int x, int k) {
	if (p[x] <= 0) return -1;
    k = dep[x] + 1 - k;
    if (k < 0) return -1;
    for (int i = 12; i >= 0; i --) {
        if (k >= (1 << i)) {
			x = dp[x][i];
			if (x <= 0) return -1;
            k -= 1 << i;
        }
    }
    return x;
}

int main() {
    scanf("%d %d %d", &n, &m, &Q);
    int x, y;
    for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
    }
    for (int i = 1; i <= n; i ++) sort(v[i].begin(), v[i].end());
    for (int i = 1; i <= Q; i ++) q[i].input(i);
    sort(q + 1, q + Q + 1);
    int p = 1;
    for (int i = 1; i <= n; i ++) {
        if (i != q[p].s) continue;
        init();
        dfs(i);
        build();
        while (p <= Q && q[p].s == i) {
            if (q[p].f == i && q[p].k == 1) ans[q[p].id] = i;
            else if (q[p].f == i && q[p].k != 1) ans[q[p].id] = -1;
            else ans[q[p].id] = query(q[p].f, q[p].k);
			p ++;
        }
        if (p > Q) break;
    }
    for (int i = 1; i <= Q; i ++) printf("%d\n", ans[i]);
}