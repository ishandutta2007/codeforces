// Problem: A. Doremy's IQ
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/A
// Memory Limit: 256 MB
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

int T, n, q, a[N], ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &q);
		rep(i, 1, n) scanf("%d", &a[i]), ans[i] = 0;
		int now = 0;
		per(i, n, 1) {
			if(now >= a[i]) ans[i] = 1;
			else if(now < q) ans[i] = 1, ++now;
		}
		rep(i, 1, n) putchar(ans[i]^48);
		puts("");
	}
	return 0;
}