//PP-Automation
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int T, n, a, b;
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d%s", &n, &a, &b, s+1);
		if(b > 0) printf("%d\n", a*n+b*n);
		else {
			int tot = 1;
			rep(i, 2, n) if(s[i] != s[i-1]) ++tot;
			tot = tot / 2 + 1;
			printf("%d\n", a*n+b*tot);
		}
	}
	return 0;
}