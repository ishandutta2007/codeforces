//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int n, now, ans;
char c;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	while(getchar() != '\n')
		;
	rep(i, 1, n) {
		c = getchar();
		if(c == ' ') {
			chkmax(ans, now);
			now = 0;
		}
		else if(c >= 'A' && c <= 'Z') ++now;
	}
	chkmax(ans, now);
	printf("%d\n", ans);
	return 0;
}