#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005;
int n, m, a[N][N], mx[N][N], g[N][N][10], f[N][N][10][10];

void init() {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			g[i][j][0] = mx[i][j];
	for(int a = 1; a < 10; a++)
		for(int i = 1; i + (1 << a) - 1 <= n; i++)
			for(int j = 1; j <= m; j++)
				g[i][j][a] = max(g[i][j][a - 1], g[i + (1 << (a - 1))][j][a - 1]);
	for(int a = 0; a < 10; a++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				f[i][j][a][0] = g[i][j][a];
	for(int a = 0; a < 10; a++)
		for(int b = 1; b < 10; b++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j + (1 << b) - 1 <= m; j++)
					f[i][j][a][b] = max(f[i][j][a][b - 1], f[i][j + (1 << (b - 1))][a][b - 1]);
}

int query(int d, int u, int l, int r) {
	int lenx = (int)log2(u - d + 1), leny = (int)log2(r - l + 1);
	return max(max(f[d][l][lenx][leny], f[u - (1 << lenx) + 1][l][lenx][leny]), 
			   max(f[d][r - (1 << leny) + 1][lenx][leny], f[u - (1 << lenx) + 1][r - (1 << leny) + 1][lenx][leny]));
}

int ask(int D, int U, int L, int R) {
	int l = 1, r = min(U - D + 1, R - L + 1), ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(query(D + mid - 1, U, L + mid - 1, R) >= mid) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = get();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!a[i][j]) continue;
			mx[i][j] = min(min(mx[i - 1][j - 1], mx[i - 1][j]), mx[i][j - 1]) + 1;
		}
	}
	init();
	int t = get();
	while(t--) {
		int d = get(), l = get(), u = get(), r = get();
		printf("%d\n", ask(d, u, l, r));
	}
	return 0;
}