#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef pair <int, int> pii;

int n, k, prv[N], up[N], aa[N], bb[N], a[N], b[N], now;
vector <pii> v[N];

bool cmp(int a, int b) {
	return a > b;
}

void dfs(int rt) {
	int sz = v[rt].size(), e = 0;
	for (int i = 0; i < sz; i ++) if (v[rt][i].first != prv[rt]) {
		prv[v[rt][i].first] = rt;
		up[v[rt][i].first] = v[rt][i].second;
        dfs(v[rt][i].first);
	}
	for (int i = 0; i < sz; i ++) if (v[rt][i].first != prv[rt]) {
		aa[++e] = a[v[rt][i].first];
		bb[e] = b[v[rt][i].first];
	}
	sort (aa + 1, aa + e + 1, cmp);
    a[rt] = up[rt];
    for (int i = 1; i < min(k, e + 1); i ++) a[rt] += aa[i];
    b[rt] = a[rt];
    now = up[rt];
    for (int i = 1; i <= min(k, e); i ++) now += aa[i];
    for (int j = 0, i; j < sz; j ++) if (v[rt][j].first != prv[rt]) {
		i = v[rt][j].first;
        b[rt] = max(b[rt], now + b[i] - max(a[i], aa[min(k,e)]));
    }
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1, x, y, z; i < n; i ++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	prv[0] = -1;
    dfs(0);
    printf("%d\n", max(a[0], b[0]));
	return 0;
}