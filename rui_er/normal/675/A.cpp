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

int a, b, c;
int sgn(int x) {return x ? (x > 0 ? 1 : -1) : 0;}

int main() {
	scanf("%d%d%d", &a, &b, &c);
	if(!c) puts(a ^ b ? "NO" : "YES");
	else {
		int qwq = sgn(b-a), qaq = abs(a-b) % c;
		puts((!qwq || qwq == sgn(c)) && !qaq ? "YES" : "NO");
	}
	return 0;
}