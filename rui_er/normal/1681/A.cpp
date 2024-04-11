// Problem: CF1681A Game with Cards
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1681A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 55;

int T, n, a[N], m, b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		scanf("%d", &m);
		rep(i, 1, m) scanf("%d", &b[i]);
		int x = *max_element(a+1, a+1+n);
		int y = *max_element(b+1, b+1+m);
		puts(x>=y?"Alice":"Bob");
		puts(x>y?"Alice":"Bob");
	}
	return 0;
}