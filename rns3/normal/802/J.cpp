#include <bits/stdc++.h>
using namespace std;

#define N 110
typedef pair <int, int> pii;

int n;
vector <pii> v[N];
bool vis[N];

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y, z; i < n; i ++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
    int q[N], e = 1, ans = 0, dist[N];
	vis[0] = 1;
	dist[0] = 0;
	q[1] = 0;
    for (int f = 1, now; f <= e; f ++) {
		now = q[f];
		for (int i = 0, u; i < v[now].size(); i ++) {
			u = v[now][i].first;
			if (vis[u]) continue;
			vis[u] = 1;
            q[++e] = u;
            dist[u] = dist[now] + v[now][i].second;
            ans = max(ans, dist[u]);
		}
    }
    printf("%d\n", ans);
	return 0;
}