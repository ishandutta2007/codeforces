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
const int N = 1e5+5;

int n, a[N]; ll Xor, Sum;

int main() {
	mulT0 {
		Xor = Sum = 0;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]), Xor ^= a[i], Sum += a[i];
		printf("2\n%lld %lld\n", Xor, Xor+Sum);
	}
	return 0;
}