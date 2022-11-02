#include <bits/stdc++.h>
using namespace std;

#define M 1101

const int mod = 1e9 + 7;

char s[M][M];
int a[M][M];
int d[M][M], u[M][M], l[M][M], r[M][M];
int ab[M][M], ad[M][M], bc[M][M], cd[M][M];
double sumx[M][M], sumy[M][M], sumxx[M][M], sumyy[M][M];

int main() {
	///freopen("4.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) a[i][j] = s[i][j]  - '0';
    }
    for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(a[i][j] == 0) u[i][j] = l[i][j] = ab[i][j] = ad[i][j] = 0;
			else {
				u[i][j] = u[i-1][j] + 1;
				l[i][j] = l[i][j-1] + 1;
                ab[i][j] = ab[i-1][j-1] + 1;
                ad[i][j] = ad[i-1][j+1] + 1;
			}
		}
    }
    for(int i = n; i; i --) {
		for(int j = n; j; j --) {
			if(a[i][j] == 0) d[i][j] = r[i][j] = bc[i][j] = cd[i][j] = 0;
			else {
				d[i][j] = d[i+1][j] + 1;
				r[i][j] = r[i][j+1] + 1;
				bc[i][j] = bc[i+1][j-1] + 1;
				cd[i][j] = cd[i+1][j+1] + 1;
			}
		}
    }
    for(int i = 1; i <= n; i ++) {
        sumx[i][0] = 0;
        sumxx[i][0] = 0;
        sumyy[i][0] = 0;
        for(int j = 1; j <= n; j ++) {
			sumx[i][j] = sumx[i][j-1];
			sumxx[i][j] = sumxx[i-1][j-1];
			sumyy[i][j] = sumyy[i-1][j+1];
            if(!a[i][j]) continue;
			sumx[i][j] += log2(a[i][j]);
			sumxx[i][j] += log2(a[i][j]);
			sumyy[i][j] += log2(a[i][j]);
        }
    }
    for(int i = 1; i <= n; i ++) {
		sumy[0][i] = 0;
		sumyy[0][i] = 0;
		for(int j = 1; j <= n; j ++) {
			sumy[j][i] = sumy[j-1][i];
            if(!a[j][i]) continue;
            sumy[j][i] += log2(a[j][i]);
		}
    }
    double ans = -1;
    int X = -1, Y = -1, TP = -1, R = -1;
    for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) if(a[i][j]){
			int x = n;
			x = min(x, u[i][j]);
			x = min(x, r[i][j]);
			x = min(x, d[i][j]);
			x = min(x, l[i][j]);
            double res = sumx[i][j + x - 1] - sumx[i][j - x] - sumy[i - x][j] + sumy[i + x - 1][j] - log2(a[i][j]);
            if(ans < res) ans = res, X = i, Y = j, TP = 0, R = x;
		}
    }
    for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) if(a[i][j]) {
            int x = n;
            x = min(x, ab[i][j]);
            x = min(x, bc[i][j]);
            x = min(x, cd[i][j]);
            x = min(x, ad[i][j]);
            double res = sumxx[i + x - 1][j + x - 1] - sumxx[i - x][j - x] + sumyy[i + x - 1][j - x + 1] - sumyy[i - x][j + x] - log2(a[i][j]);
            if(ans < res) ans = res, X = i, Y = j, TP = 1, R = x;
		}
    }
    if(ans < 0) return puts("0");
    if(!TP) {
        int val = 1;
        for(int i = 1; i < R; i ++) {
			val = 1ll * val * a[X - i][Y] % mod;
			val = 1ll * val * a[X + i][Y] % mod;
			val = 1ll * val * a[X][Y - i] % mod;
			val = 1ll * val * a[X][Y + i] % mod;
        }
        val = 1ll * val * a[X][Y] % mod;
        cout << val << endl;
        return 0;
    }
    int val = 1;
    for(int i = 1; i < R; i ++) {
		val = 1ll * val * a[X - i][Y - i] % mod;
		val = 1ll * val * a[X - i][Y + i] % mod;
		val = 1ll * val * a[X + i][Y - i] % mod;
		val = 1ll * val * a[X + i][Y + i] % mod;
    }
    val = 1ll * val * a[X][Y] % mod;
    cout << val << endl;
}