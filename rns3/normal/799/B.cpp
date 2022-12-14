#include <bits/stdc++.h>
using namespace std;

#define N 400010

int n, m, id[4][N], a, c[4], cost[N], t[4];
bool vis[N];

bool cmp(int i, int j) {
	return cost[i] < cost[j];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &cost[i]);
	for (int i = 0; i < n * 2; i ++) {
		scanf("%d", &a);
		id[a][++c[a]] = i % n + 1;
	}
	for (a = 1; a <= 3; a ++) {
		sort (id[a] + 1, id[a] + c[a] + 1, cmp);
		t[a] = 1;
	}
    scanf("%d", &m);
    while (m --) {
		scanf("%d", &a);
		while (t[a] <= c[a] && vis[id[a][t[a]]]) t[a] ++;
        if (t[a] > c[a]) printf("-1");
        else {
			printf("%d", cost[id[a][t[a]]]);
			vis[id[a][t[a]]] = 1;
			t[a] ++;
        }
        if (m) printf(" ");
        else puts("");
    }
	return 0;
}