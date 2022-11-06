// Problem: CF1656C Make Equal With Mod
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1656C
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
const int N = 2e5+5;

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		int zero = 0, one = 0, cons = 0;
		rep(i, 1, n) {
			zero |= !a[i];
			one |= a[i] == 1;
			if(i > 1) cons |= a[i] == a[i-1] + 1;
		}
		if(zero && one) puts("NO");
		else if(one) puts(cons?"NO":"YES");
		else puts("YES");
	}
	return 0;
}