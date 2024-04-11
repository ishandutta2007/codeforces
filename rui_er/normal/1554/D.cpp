//luogu@rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, tot;
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		tot = 0;
		scanf("%d", &n);
		if(n == 1) s[++tot] = 'a';
		else if(n & 1) {
			rep(i, 1, n/2-1) s[++tot] = 'a';
			s[++tot] = 'b'; s[++tot] = 'c';
			rep(i, n/2+2, n) s[++tot] = 'a';
		}
		else {
			rep(i, 1, n/2-1) s[++tot] = 'a';
			s[++tot] = 'b';
			rep(i, n/2+1, n) s[++tot] = 'a';
		}
		s[tot+1] = '\0';
		printf("%s\n", s+1);
	}
	return 0;
}