// Problem: CF1333B Kind Anton
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1333B
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
const int N = 1e5+5;

int T, n, a[N], b[N], caninc[N], candec[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		rep(i, 1, n) {
			caninc[i] = caninc[i-1] | (a[i-1] > 0);
			candec[i] = candec[i-1] | (a[i-1] < 0);
		}
		int ok = 1;
		rep(i, 1, n) {
			if(a[i] < b[i]) ok &= caninc[i];
			if(a[i] > b[i]) ok &= candec[i];
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}