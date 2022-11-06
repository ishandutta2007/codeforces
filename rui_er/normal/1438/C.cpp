// Problem: CF1438C Engineer Artem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1438C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int T, n, m, a[N][N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) {
			rep(j, 1, m) {
				scanf("%d", &a[i][j]);
				if(((i + j) & 1) ^ (a[i][j] & 1)) ++a[i][j];
			}
		}
		rep(i, 1, n) rep(j, 1, m) printf("%d%c", a[i][j], " \n"[j==m]);
	}
	return 0;
}