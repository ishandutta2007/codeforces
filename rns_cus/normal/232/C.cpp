#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 88
#define M 222

int t, n, hn[N], tn[N];
LL a, b, f[N];
pair <LL, int> head[N][M], tail[N][M];

int dist(LL a, LL b, int n) {
	if (a == b) return 0;
	if (a == b - 1) return 1;
	if (a == 1) {
		for (int i = 0; i < hn[n]; i ++) {
			if (head[n][i].first == b) return head[n][i].second;
		}
	}
	if (b == f[n]) {
		for (int i = 0; i < tn[n]; i ++) {
			if (tail[n][i].first == a) return tail[n][i].second;
		}
	}
	int rlt;
	if (a > f[n-1]) rlt = dist(a - f[n-1], b - f[n-1], n - 2);
	else if (b <= f[n-1]) {
		rlt = min(dist(1, a, n - 1) + dist(b, f[n-1], n - 1), dist(1, b, n - 1) + dist(a, f[n-1], n - 1)) + 2;
		rlt = min(rlt, dist(a, b, n - 1));
	}
	else {
		rlt = min(dist(1, a, n - 1), dist(a, f[n-1], n - 1)) + dist(1, b - f[n-1], n - 2) + 1;
	}
	if (a == 1) head[n][hn[n]++] = make_pair(b, rlt);
	if (b == f[n]) tail[n][tn[n]++] = make_pair(a, rlt);
	return rlt;
}

int main() {
	f[0] = 1, f[1] = 2;
	for (int i = 2; i < N; i ++) f[i] = f[i-1] + f[i-2];
	scanf("%d %d", &t, &n);
	while (t --) {
		scanf("%I64d %I64d", &a, &b);
		if (a > b) swap(a, b);
		int m = min(n, lower_bound(f, f + N, b) - f + 1);
		for (int i = 1; i <= m; i ++) hn[i] = tn[i] = 0;
		printf("%d\n", dist(a, b, m));
	}
	return 0;
}