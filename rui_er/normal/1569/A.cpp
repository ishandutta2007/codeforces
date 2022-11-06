//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 55; 

int T, n;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%s", &n, s+1);
		int ok = 0;
		rep(i, 1, n-1) if(s[i] != s[i+1]) {ok = i; break;}
		if(ok) printf("%d %d\n", ok, ok+1);
		else puts("-1 -1");
	}
	return 0;
}