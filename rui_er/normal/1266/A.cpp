//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int T;
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%s", s+1);
		int zero = 0, even = 0, div3 = 0;
		int n = strlen(s+1);
		rep(i, 1, n) {
			if(s[i] == '0') {
				if(!zero) zero = 1;
				else even = 1;
			}
			else if(!((s[i] - '0') & 1)) even = 1;
			div3 = (div3 + s[i] - '0') % 3;
		}
		if(zero && even && !div3) puts("red");
		else puts("cyan");
	}
	return 0;
}