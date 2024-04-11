//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int T, n;
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%s", &n, s+1);
		int fst = 0;
		rep(i, 1, n) if(s[i] != '?') {fst = i; break;}
		if(!fst) {
			rep(i, 1, n) printf("%c", "RB"[i&1]);
			puts("");
			continue;
		}
		per(i, fst-1, 1) s[i] = s[i+1] ^ 'B' ^ 'R';
		rep(i, fst+1, n) if(s[i] == '?') s[i] = s[i-1] ^ 'B' ^ 'R';
		printf("%s\n", s+1);
	}
	return 0;
}