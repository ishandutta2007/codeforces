// Problem: CF1352F Binary String Reconstruction
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1352F
// Memory Limit: 250 MB
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

int T, n0, n1, n2;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &n0, &n1, &n2);
		if(!n1) {
			if(n0) rep(i, 0, n0) putchar(48);
			else  rep(i, 0, n2) putchar(49);
		}
		else {
			rep(i, 0, n0) putchar(48);
			--n1;
			rep(i, 0, n2) putchar(49);
			int u = 49;
			rep(i, 1, n1) putchar(u ^= 1);
		}
		puts("");
	}
	return 0;
}