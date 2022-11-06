// Problem: CF990D Graph And Its Complement
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF990D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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

int n, a, b;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	if(a > 1 && b > 1) puts("NO");
	else if(a == 1 && b == 1) {
		if(n == 2 || n == 3) puts("NO");
		else {
			puts("YES");
			rep(i, 1, n) {
				rep(j, 1, n) putchar("01"[abs(i-j)==1]);
				puts("");
			}
		}
	}
	else if(a == 1) {
		puts("YES");
		rep(i, 1, n) {
			rep(j, 1, n) putchar("10"[i==j||min(i,j)>=b&&abs(i-j)==1]);
			puts("");
		}
	}
	else {
		puts("YES");
		rep(i, 1, n) {
			rep(j, 1, n) putchar("01"[min(i,j)>=a&&abs(i-j)==1]);
			puts("");
		}
	}
	return 0;
}