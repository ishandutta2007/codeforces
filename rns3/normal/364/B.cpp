#include <bits/stdc++.h>
using namespace std;

#define N 55
#define M 550000

int n, c[N], d, k[M];
bool vis[M];

int main() {
	scanf("%d %d", &n, &d);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
    vis[0] = 1;
    for (int i = 1; i <= n; i ++) for (int j = M - 1; j >= 0; j --) if (vis[j]) vis[j+c[i]] = 1;
    k[0] = 0;
    int e = 0;
    for (int i = 1; i < M; i ++) if (vis[i]) k[++e] = i;
    k[e+1] = 1e9;
    int i = 0, cnt = 0;
    while (1) {
        int j;
        for (j = i + 1; j <= e; j ++) if (k[i] + d < k[j]) break;
		j --;
		if (i == j) break;
		i = j;
		cnt ++;
    }
    printf("%d %d\n", k[i], cnt);
	return 0;
}