#include <bits/stdc++.h>
using namespace std;

#define M 2001

int f[M][M], c[M][2];
char s[M][M];

int main() {
	///freopen("3.in", "r", stdin);
	int n, m, x, y;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i ++) {
    	for(int j = 1; j <= m; j ++) {
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1];
			f[i][j] += (s[i][j] == '.');

    	}
    }
    c[0][0] = c[0][1] = 0;
    for(int i = 1; i <= m; i ++) {
        c[i][0] = c[i][1] = 1e9;
        for(int j = x; j <= y; j ++) if(i >= j){
            int res = j * n - (f[n][i] - f[n][i-j]);
           	res += c[i-j][1];
            c[i][0] = min(c[i][0], res);
            res = (f[n][i] - f[n][i-j]);
            res += c[i-j][0];
            c[i][1] = min(c[i][1], res);
        }
    }
	printf("%d\n", min(c[m][0], c[m][1]));
}