//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, m;
char s[N], t[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%s%s", s+1, t+1);
		n = strlen(s+1); m = strlen(t+1);
		if(n < m) {puts("NO"); continue;}
		int pos_S = n, pos_T = m, ok = 1;
		while(pos_T) {
			while(pos_S > 0 && s[pos_S] != t[pos_T]) {--pos_S; --pos_S;}
			if(pos_S <= 0) {ok = 0; break;}
			--pos_S; --pos_T;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}