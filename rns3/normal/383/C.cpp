#include <bits/stdc++.h>
using namespace std;

#define N 220200
#define M 2020
typedef long long LL;

int n, T, a[N], st[N], en[N], type, id[N], rk[N], b[N], add[M], K;
bool tag[N], vis[N];

vector <int> v[N];

int tim;
void dfs(int rt) {
	st[rt] = ++tim;
	rk[tim] = rt;
	id[rt] = tim;
	vis[rt] = 1;
	for (int i = 0, j, sz = v[rt].size(); i < sz; i ++) {
		j = v[rt][i];
        if (vis[j]) continue;
        tag[j] = 1 - tag[rt];
        dfs(j);
	}
	en[rt] = tim;
}

void myadd(int k, int d) {
	int h = (k + K - 1) / K;
	for (int i = 1; i < h; i ++) add[i] += d;
    for (int i = (h - 1) * K + 1; i <= k; i ++) a[i] += d;
}

int calc(int k) {
	return add[(k+K-1)/K] + a[k];
}

int main() {
	scanf("%d %d", &n, &T);
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    for (int i = 1, x, y; i < n; i ++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
    }
    tag[1] = 0;
    dfs(1);
    for (int i = 1; i <= n; i ++) {
		a[i] = b[rk[i]];
		if (tag[rk[i]]) a[i] = -a[i];
	}
	int k, dd, ans, flag;
	K = sqrt(n) + 1;
    while (T --) {
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d %d", &k, &dd);
			if (tag[k]) flag = -1;
			else flag = 1;
            myadd(st[k] - 1, -flag * dd);
            myadd(en[k], flag * dd);
		}
		else {
			scanf("%d", &k);
			ans = calc(id[k]);
			if (tag[k]) ans = -ans;
			printf("%d\n", ans);
		}
    }
	return 0;
}