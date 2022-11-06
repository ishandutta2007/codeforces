//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int W = 2e5, N = W + 5; 

int n, k, q, d[N], a[N], s[N];

int main() {
	scanf("%d%d%d", &n, &k, &q);
	rep(i, 1, n) {int a, b; scanf("%d%d", &a, &b); ++d[a]; --d[b+1];}
	rep(i, 1, W) a[i] = a[i-1] + d[i], s[i] = s[i-1] + (a[i] >= k);
	rep(i, 1, q) {int a, b; scanf("%d%d", &a, &b); printf("%d\n", s[b]-s[a-1]);}
	return 0;
}