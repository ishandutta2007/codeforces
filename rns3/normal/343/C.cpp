#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL INF = 2 * 1ll * 1e5 * 1e5;

#define N 100010

int n, m;
LL h[N], p[N];

bool func(LL now, LL from, LL to, LL limi) {
	LL ans;
    if (now >= p[from] && now <= p[to]) ans = min(now - p[from], p[to] - now) + p[to] - p[from];
    else ans = max(now - p[from], p[to] - now);
    return ans <= limi;
}

bool ok(LL x) {
	int tag = 1, old;
    for (int i = 1; i <= n; i ++) {
    	old = tag;
		while(func(h[i], old, tag, x)) {
			tag ++;
			if (tag > m) return 1;
		}
    }
    return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%I64d", &h[i]);
	for (int i = 1; i <= m; i ++) scanf("%I64d", &p[i]);
	LL st = -1, en = INF;
    while (st < en - 1) {
		LL mid = (st + en) / 2;
		if (ok(mid)) en = mid;
		else st = mid;
    }
    printf("%I64d\n", en);
	return 0;
}