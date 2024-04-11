#include <bits/stdc++.h>
using namespace std;
#define M 200100

int n, m;
vector<int> v[M];
int a[M], ok[M], f[M];

int sum[M], down[M], up[M], A[M], B[M];
int size[M];

void dfs(int x, int fa) {
	sum[x] = ok[x];
	A[x] = 0, B[x] = 0;
	down[x] = 0;
	size[x] = 1;
	for (int y, i = 0; i < v[x].size(); i++) {
		if ((y = v[x][i]) == fa) {
			continue;
		}
		dfs(y, x);
		size[x] += size[y];
		if (size[y] == down[y]) {
			sum[x] += size[y];
		} else if (down[y] > A[x]) {
			B[x] = A[x];
			A[x] = down[y];
		} else if (down[y] > B[x]) {
			B[x] = down[y];
		}
	}
	if (!ok[x]) {
		up[x] = 0;
		down[x] = sum[x] = A[x] = B[x] = 0;
		return;
	}
	down[x] = sum[x] + A[x];
	//printf("down[%d] = %d\n", x, down[x]);
}

void update(int x, int fa) {
	for (int y, i = 0; i < v[x].size(); i++) {
		y = v[x][i];
		if (y == fa) {
			continue;
		}
		f[y] = down[y];
		if (!ok[x] || !ok[y]) {
			up[y] = 0;
			update(y, x);
			continue;
		}

		int Sum = sum[x], AA = A[x], BB = B[x];
		if (size[y] == down[y]) {
			Sum -= size[y];
		} else {
			if (AA == down[y]) {
				AA = BB;
			}
		}
		if (up[x] == n - size[x]) {
			Sum += up[x];
		} else {
			AA = max(AA, up[x]);
		}

		up[y] = Sum + AA;

		if (up[y] == n - size[y]) {
			f[y] = down[y] + up[y];
		} else {
			f[y] = sum[y] + max(A[y], up[y]);
		}
		update(y, x);
	}
}

int main() {
	//freopen("D1.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int x, y, i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int mn = 0, mx = 1000001;
	//mn = 4, mx = 6;
	while (mn < mx - 1) {
		//printf("mn = %d, mx = %d\n", mn, mx);
		int mid = (mn + mx) / 2;
		//mid = 5;
		for (int i = 1; i <= n; i++) {
			ok[i] = a[i] >= mid;
			f[i] = 0;
			down[i] = 0;
			up[i] = 0;
			A[i] = B[i] = 0;
			size[i] = 0;
		}
		dfs(1, 0);
		f[1] = down[1];
		update(1, 0);
		//printf("~~%d; %d\n", *max_element(f + 1, f + n + 1), m);
		//return 0;
		if (*max_element(f + 1, f + n + 1) >= m) {
			mn = mid;
		} else {
			mx = mid;
		}
	}
	printf("%d\n", mn);
	return 0;
}