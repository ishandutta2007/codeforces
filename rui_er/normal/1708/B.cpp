// Problem: CF1708B Difference of GCDs
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1708B
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
const int N = 2e3+5;

int T, n, l, r;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &n, &l, &r);
		rep(i, 1, n) if(l / i == r / i && l % i) {puts("NO"); goto qwq;}
		puts("YES");
		rep(i, 1, n) printf("%d%c", r/i*i, " \n"[i==n]);
		qwq:;
	}
	return 0;
}