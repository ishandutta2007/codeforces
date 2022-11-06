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
const int N = 105;

int n, m, a[N], b[N], Xor, lst;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]), Xor ^= a[i];
	rep(i, 1, m) scanf("%d", &b[i]), Xor ^= b[i];
	if(Xor) return puts("NO"), 0;
	puts("YES");
	rep(i, 1, n-1) {
		rep(j, 1, m-1) printf("0 ");
		printf("%d\n", a[i]); lst ^= a[i];
	}
	rep(i, 1, m-1) printf("%d ", b[i]);
	printf("%d\n", lst^b[m]);
	return 0;
}