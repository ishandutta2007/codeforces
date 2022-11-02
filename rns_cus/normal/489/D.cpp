#include <bits/stdc++.h>
using namespace std;
#define N 3030

int n, m, a, b;
vector <int> v[N];
long long f[N][N], ans;

void update(int x) {
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		for (int j = 0; j < v[y].size(); j ++) f[x][v[y][j]] ++;
	}
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &m);
    while (m --) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
    }
    for (int i = 1; i <= n; i ++) update(i);
    for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) if (i != j) ans += f[i][j] * (f[i][j] - 1) / 2;
    }
    printf("%I64d\n", ans);
	return 0;
}