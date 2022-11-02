#include <bits/stdc++.h>

using namespace std;

#define N 1010

int n, m;
int a[N];
double f[N][N], g[N], h[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
    for(int i = 1; i <= n; i ++) {
    	for(int j = 1; j <= n; j ++) {
    		if(a[i] > a[j]) f[i][j] = 1.;
			else f[i][j] = 0.;
    	}
    }
    for(int i = 1, x, y; i <= m; i ++) {
    	scanf("%d%d", &x, &y);
      for(int j = 1; j <= n; j ++) {
        if(j == x) g[j] = 0.;
        else if(j == y) g[j] = 0.5; else g[j] = (f[y][j] + f[x][j]) * 0.5;
        if(j == y) h[j] = 0.;
        else if(j == x) h[j] = 0.5; else h[j] = g[j];
      }
      for(int j = 1; j <= n; j ++) {
        f[x][j] = g[j];
        f[j][x] = 1. - g[j];
        f[y][j] = h[j];
        f[j][y] = 1. - h[j];
      }
    }
    double ans = 0.;
    for(int i = 1; i < n; i ++) for(int j = i + 1; j <= n; j ++) ans += f[i][j];
    printf("%.12lf\n", ans);
	return 0;
}