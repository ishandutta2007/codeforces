//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;

int a, b, k, pre1;

int main() {
	scanf("%d%d%d", &a, &b, &k);
	if(!k) {
		puts("Yes");
		rep(i, 1, b) putchar('1');
		rep(i, 1, a) putchar('0');
		puts("");
		rep(i, 1, b) putchar('1');
		rep(i, 1, a) putchar('0');
		puts("");
	}
	else if(!a || b == 1) puts("No");
	else if(a + b - 2 < k) puts("No");
	else {
		puts("Yes");
		putchar('1');
		putchar('1');
		rep(i, 1, k-1) {
			if(i <= b - 2) putchar('1');
			else putchar('0');
		}
		putchar('0');
		rep(i, k, a+b-3) {
			if(i <= b - 2) putchar('1');
			else putchar('0');
		}
		puts("");
		putchar('1');
		putchar('0');
		rep(i, 1, k-1) {
			if(i <= b - 2) putchar('1');
			else putchar('0');
		}
		putchar('1');
		rep(i, k, a+b-3) {
			if(i <= b - 2) putchar('1');
			else putchar('0');
		}
		puts("");
	}
	return 0;
}