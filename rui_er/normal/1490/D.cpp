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

int n, a[N], dep[N];
void build(int l, int r, int d) {
	if(l > r) return;
	int mx = 0, id = 0;
	rep(i, l, r) if(a[i] > mx) {mx = a[i]; id = i;}
	dep[id] = d;
	build(l, id-1, d+1);
	build(id+1, r, d+1);
}

int main() {
	mulT0 {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		build(1, n, 0);
		rep(i, 1, n) printf("%d%c", dep[i], " \n"[i==n]);
		rep(i, 1, n) dep[i] = 0;
	}
	return 0;
}