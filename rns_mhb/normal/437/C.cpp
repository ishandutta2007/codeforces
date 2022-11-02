#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m, v[N], id[N], x, y;
long long sum;
bool E[N][N], vis[N];

bool cmp(int r, int s) {return v[r] > v[s];}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &v[i]);
    while (m --) {
		scanf("%d%d", &x, &y);
		E[x][y] = 1;
		E[y][x] = 1;
    }
    for (int i = 1; i <= n; i ++) id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
		vis[id[i]] = 1;
        for (int j = 1; j <= n; j ++) if (E[id[i]][j] && !vis[j]) sum += 1LL * v[j];
    }
    printf("%I64d", sum);
}