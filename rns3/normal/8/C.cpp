#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

#define M 25
#define inf 1e9

int X, Y, x[M], y[M], n, Dis, dis[M][M], bit[M], a[M], f[1<<M];
pair <short int, short int> ans[1<<M];
vector <int> v;

int dist(int x, int y) {
	return (x * x + y * y);
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &X, &Y);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d %d", &x[i], &y[i]);
	x[n] = X, y[n] = Y;
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= n; j ++)
			dis[i][j] = dist(x[i] - x[j], y[i] - y[j]);
	for (int i = 0; i < n; i ++) Dis += dis[i][n];

	int N = 1 << n;
	for (int i = 0; i < N; i ++) f[i] = inf;
	f[0] = 0;
	for (int i = 1; i < N; i ++) {
		int I = i, Bit = 0;
		for (int j = 0; j < n; j ++) {
			bit[j] = I & 1, I >>= 1;
			if (bit[j]) a[++Bit] = j;
		}
		for (int k = 1; k <= Bit; k ++) {
			if (f[i] > f[i-(1<<a[k])] + dis[a[k]][n])
				f[i] = f[i-(1<<a[k])] + dis[a[k]][n], ans[i].first = a[k], ans[i].second = -1;
		}
		for (int k = 2; k <= Bit; k ++) {
			if (f[i] > f[i-(1<<a[1])-(1<<a[k])] + dis[a[1]][a[k]])
				f[i] = f[i-(1<<a[1])-(1<<a[k])] + dis[a[1]][a[k]], ans[i].first = a[1], ans[i].second = a[k];
		}
	}
	int m = N - 1;
	printf("%d\n", f[m] + Dis);
	while (m) {
		v.push_back(0);
		v.push_back(ans[m].first + 1);
		if (ans[m].second != -1) v.push_back(ans[m].second + 1);
		if (ans[m].second == -1) m -= (1 << ans[m].first);
		else m -= (1 << ans[m].first) + (1 << ans[m].second);
	}
	for (int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
	puts("0");
	return 0;
}