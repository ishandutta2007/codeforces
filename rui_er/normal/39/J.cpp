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
const int N = 1e6+5;

char a[N], b[N];
int n, L, R;

int main() {
	scanf("%s%s", a+1, b+1);
	L = 1; R = n = strlen(b+1);
	while(L <= n && a[L] == b[L]) ++L;
	while(R >= 1 && a[R+1] == b[R]) --R;
	if(L > R) {
		printf("%d\n", L-R);
		rep(i, R+1, L) printf("%d%c", i, " \n"[i==L]);
	}
	else puts("0");
	return 0;
}