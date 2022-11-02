#include <bits/stdc++.h>

using namespace std;

#define N 155
#define mod 1000000007

int f[N][N], ff[N][N], fff[N][N];
int g[N][N][N], sum[N][N][N], h[N][N][N];
int n, m;

inline void add(int &x, int y) { x += y; if(x >= mod) x -= mod; }
inline void sub(int &x, int y) { x -= y; if(x < 0) x += mod; }

int main() {
	//freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) f[i][0] = ff[i][0] = fff[i][0] = 1;
    for(int i = 1; i <= m; i ++) for(int j = 1; j < n; j ++) {
		fff[i][j] = ff[i][j] = f[i][j] = 1;
    	for(int k = 1; k <= i; k ++) {
    		add(f[i][j], 1LL * (i - k + 1) * f[k][j-1] % mod);
    		if(k < i) {
				add(ff[i][j], 1LL * (i - k + 1) * f[k][j-1] % mod);
				add(fff[i][j], 1LL * (i - k) * f[k][j-1] % mod);
    		}
    	}
    }
    for(int i = 1; i <= m; i ++) for(int j = i; j <= m; j ++) {
		g[i][j][0] = 1; sum[i][j][0] = m - j + 1;
		h[i][j][0] = (m - j + 1) * (j - i + 1);
    }
    for(int i = 1; i < n; i ++) {
    	for(int j = 1; j <= m; j ++) {
    		for(int k = j; k <= m; k ++) {
                g[j][k][i] = (fff[k-j+1][i] + h[j][k][i-1]) % mod;
    		}
    		for(int k = m; k >= j; k --) sum[j][k][i] = (sum[j][k+1][i] + g[j][k][i]) % mod;
    	}
    	for(int j = m; j; j --) {
    		for(int k = j; k <= m; k ++) h[j][k][i] = (h[j+1][k][i] + sum[j][k][i]) % mod;
    	}
    }
    int rt = 0;
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) for(int k = j; k <= m; k ++) {
		int tp = g[j][k][n-i];
		add(tp, g[m-k+1][m-j+1][n-i]);
		sub(tp, ff[k-j+1][n-i]);
		if(i < n) {
			sub(tp, sum[j][k][n-i-1]);
			sub(tp, sum[m-k+1][m-j+1][n-i-1]);
		}
    	add(rt, 1LL * tp * f[k-j+1][i-1] % mod);
    }
    cout << rt << endl;
	return 0;
}