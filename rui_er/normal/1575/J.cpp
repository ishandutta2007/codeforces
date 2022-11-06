// Problem: CF1575J Jeopardy of Dropped Balls
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1575J
// Memory Limit: 500 MB
// Time Limit: 2000 ms
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
const int N = 1e3+5;

int n, m, k, a[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
	while(k--) {
		int x = 1, y;
		scanf("%d", &y);
		while(x <= n) {
			int i = a[x][y];
			a[x][y] = 2;
			if(i == 1) ++y;
			else if(i == 2) ++x;
			else --y;
		}
		printf("%d ", y);
	}
	return 0;
}