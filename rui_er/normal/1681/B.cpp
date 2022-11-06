// Problem: CF1681B Card Trick
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1681B
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
const int N = 2e5+5;

int T, n, a[N], m, b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 0, n-1) scanf("%d", &a[i]);
		scanf("%d", &m);
		int qwq = 0;
		rep(i, 0, m-1) scanf("%d", &b[i]), qwq = (qwq + b[i]) % n;
		printf("%d\n", a[qwq]);
	}
	return 0;
}