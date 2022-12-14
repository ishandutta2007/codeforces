#include <bits/stdc++.h>
using namespace std;

#define N 1010
const double pie = 3.14159265358;

int n, p[N], dist[N];
vector <int> v[N];

struct circle {
	int x, y, r;
}c[N];

bool cmp(circle a, circle b) {
	return a.r > b.r;
}

bool inok(circle a, circle b) {
    return 1ll * a.r * a.r > 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &c[i].x, &c[i].y, &c[i].r);
	}
	sort (c + 1, c + n + 1, cmp);
    for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) {
        if (inok(c[i], c[j])) p[j] = max(p[j], i);
    }
    for (int i = 1; i <= n; i ++) v[p[i]].push_back(i);
	dist[0] = 0;
	int q[N], e = 0;
	q[0] = 0;
	for (int f = 0; f <= e; f ++) {
        for (int i = 0, sz = v[q[f]].size(), u; i < sz; i ++) {
			u = v[q[f]][i];
            dist[u] = dist[q[f]] + 1;
            q[++e] = u;
        }
	}
    long long ans = 0;
    for (int i = 1; i <= n; i ++) {
		if (dist[i] == 1 || dist[i] % 2 == 0) ans += 1ll * c[i].r * c[i].r;
		else ans -= 1ll * c[i].r * c[i].r;
    }
    double rlt = 1.0 * ans * pie;
    printf("%.12lf\n", rlt);
	return 0;
}