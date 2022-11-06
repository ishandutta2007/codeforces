// Problem: C. awoo's Favorite Problem
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforc.es/contest/1697/problem/C
// Memory Limit: 256 MB
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
const int N = 1e5+5;

int T, n;
char s[N], t[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%s%s", &n, s+1, t+1);
		int buc[3];
		memset(buc, 0, sizeof(buc));
		rep(i, 1, n) {
			++buc[s[i]-'a'];
			--buc[t[i]-'a'];
		}
		int ok = 1;
		rep(i, 0, 2) ok &= !buc[i];
		if(!ok) puts("NO");
		else {
			int x = 1, y = 1;
			while(x <= n && y <= n) {
				while(x <= n && s[x] == 'b') ++x;
				while(y <= n && t[y] == 'b') ++y;
				if(s[x] != t[y]) {ok = 0; break;}
				++x; ++y;
			}
			int a = 0, c = 0;
			rep(i, 1, n) {
				if(s[i] == 'a') ++a;
				if(t[i] == 'a') --a;
				if(s[i] == 'c') ++c;
				if(t[i] == 'c') --c;
				if(a < 0 || c > 0) {ok = 0; break;}
			}
			puts(ok?"YES":"NO");
		}
	}
	return 0;
}