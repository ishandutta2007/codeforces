//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, A, B, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &n, &A, &B);
		if(abs(A - B) > 1 || A + B > n - 2) puts("-1");
		else if(A == B) {
			int L = 1, R = 2 * A + 2;
			rep(i, 0, A) printf("%d %d ", L++, R--);
			rep(i, 2*A+3, n) printf("%d ", i);
			puts("");
		}
		else if(A > B) {
			int R = n, L = n - 2 * A;
			printf("%d ", L++);
			rep(i, 1, A) printf("%d %d ", R--, L++);
			per(i, n-2*A-1, 1) printf("%d ", i);
			puts("");
		}
		else {
			int L = 1, R = 2 * B + 1;
			printf("%d ", R--);
			rep(i, 1, B) printf("%d %d ", L++, R--);
			rep(i, 2*B+2, n) printf("%d ", i);
			puts("");
		}
	}
    return 0;
}