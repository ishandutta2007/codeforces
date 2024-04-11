#include <bits/stdc++.h>
using namespace std;
#define N 200200

struct gadget {
	int cost, id;
	bool operator < (const gadget &b) const {
		return cost < b.cost;
	}
} c1[N], c2[N];

int n, m, k, c, a[N], b[N], type, cost, type1, type2;
int m1, m2;

typedef long long LL;

const LL inf = 1ll << 60;

LL sum1[N], sum2[N], Min1[N], Min2[N], num1[N], num2[N];

int get_max(int co, int d) {
    int st = 0, en = m2 + 1;
    while (en - st > 1) {
		int mid = (st + en) / 2;
		if (co >= sum2[mid] * Min2[d]) st = mid;
		else en = mid;
    }
    return st;
}

bool ok(int d) {
	int A = Min1[d], B = Min2[d];
	for (int i = 0; i <= m1; i ++) {
		LL remain = c - sum1[i] * Min1[d];
        if (remain < 0) return 0;
        int j = get_max(remain, d);
		if (i + j >= k) {
			type1 = i, type2 = min(j, k - i);
			return 1;
		}
	}
	return 0;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d %d\n", &n, &m, &k, &c);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &type, &cost);
		if (type == 1) c1[++m1].cost = cost, c1[m1].id = i;
		else c2[++m2].cost = cost, c2[m2].id = i;
	}
	Min1[0] = Min2[0] = inf;
	for (int i = 1; i <= n; i ++) {
		Min1[i] = Min1[i-1], num1[i] = num1[i-1];
		if (a[i] < Min1[i-1]) Min1[i] = a[i], num1[i] = i;
		Min2[i] = Min2[i-1], num2[i] = num2[i-1];
		if (b[i] < Min2[i-1]) Min2[i] = b[i], num2[i] = i;
	}
	sort(c1 + 1, c1 + m1 + 1);
	for (int i = 1; i <= m1; i ++) sum1[i] = sum1[i-1] + c1[i].cost;
	sort(c2 + 1, c2 + m2 + 1);
	for (int i = 1; i <= m2; i ++) sum2[i] = sum2[i-1] + c2[i].cost;
	if (!ok(n)) {
		puts("-1"); return 0;
	}
	int st = 0, en = n;
	while (en - st > 1) {
		int mid = (st + en) / 2;
		if (ok(mid)) en = mid;
		else st = mid;
	}
	printf("%d\n", en);
	for (int i = 1; i <= type1; i ++) printf("%d %d\n", c1[i].id, num1[en]);
	for (int i = 1; i <= type2; i ++) printf("%d %d\n", c2[i].id, num2[en]);
	return 0;
}