// LUOGU_RID: 90744813
// Problem: T188194 
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T188194
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n, m, a[N], dp[N][20], d[20][20];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	memset(dp, 0x3f, sizeof(dp));
	memset(d, 0x3f, sizeof(d));
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		rep(j, 0, 19) if((a[i] >> j) & 1) dp[i][j] = i;
	}
	per(i, n, 1) {
		rep(j, 0, 19) {
			if((a[i] >> j) & 1) {
				rep(k, 0, 19) {
					chkmin(dp[i][k], d[j][k]);
				}
			}
		}
		rep(j, 0, 19) {
			if((a[i] >> j) & 1) {
				rep(k, 0, 19) {
					chkmin(d[j][k], dp[i][k]);
				}
			}
		}
	}
	while(m--) {
		int x, y, ok = 0;
		scanf("%d%d", &x, &y);
		rep(i, 0, 19) {
			if((a[y] >> i) & 1) {
				ok |= dp[x][i] <= y;
			}
		}
		puts(ok?"Shi":"Fou");
	}
	return 0;
}