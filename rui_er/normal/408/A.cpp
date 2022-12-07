// LUOGU_RID: 96472012
// Problem: CF408A Line to Cashier
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF408A
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int n, k[N], m[N][N], ans = 2147483647;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &k[i]);
	rep(i, 1, n) {
		int now = 0;
		rep(j, 1, k[i]) {
			scanf("%d", &m[i][j]);
			now += m[i][j] * 5 + 15;
		}
		chkmin(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}