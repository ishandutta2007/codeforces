#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define pb push_back

vector <int> v[N];
int n, m, s, t;
int ds[N], dt[N];

void bfs(int s, int *d) {
	queue <int> q;
	for (int i = 1; i <= n; i ++) d[i] = -1;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
		int x = q.front(); q.pop();
        for (int i = 0; i < v[x].size(); i ++) {
            int y = v[x][i];
            if (d[y] < 0) {
				d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    return;
}

int main() {
    int x, y;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &x, &y);
        v[x].pb(y);
        v[y].pb(x);
    }
    bfs(s, ds);
    bfs(t, dt);
    int dist = ds[t];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            if (dist <= 1 + ds[i] + dt[j] && dist <= 1 + dt[i] + ds[j]) ans ++;
        }
    }
    ans -= m;
    printf("%d\n", ans);
	return 0;
}