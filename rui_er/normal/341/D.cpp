//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n, m;
struct BIT {
	int nd[N][N];
	int lowbit(int x) {return x & (-x);}
	void modify(int x, int y, int delta) {
		for(int i=x;i<=n;i+=lowbit(i))
			for(int j=y;j<=n;j+=lowbit(j))
				nd[i][j] ^= delta;
	}
	int query(int x, int y) {
		int ans = 0;
		for(int i=x;i;i-=lowbit(i))
			for(int j=y;j;j-=lowbit(j))
				ans ^= nd[i][j];
		return ans;
	}
}a[4];
void modify(int x, int y, int delta) {
	a[0].modify(x, y, delta);
	a[1].modify(x, y, delta*(x&1));
	a[2].modify(x, y, delta*(y&1));
	a[3].modify(x, y, delta*(x*y&1));
}
int query(int x, int y) {
	int ans = 0;
	ans ^= a[0].query(x, y) * ((x + 1) * (y + 1) & 1);
	ans ^= a[1].query(x, y) * ((y + 1) & 1);
	ans ^= a[2].query(x, y) * ((x + 1) & 1);
	ans ^= a[3].query(x, y);
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	while(m--) {
		int op, x, y, X, Y, delta;
		scanf("%d%d%d%d%d", &op, &x, &y, &X, &Y);
		if(op == 2) {
			scanf("%d", &delta);
			modify(x, y, delta);
			modify(x, Y+1, delta);
			modify(X+1, y, delta);
			modify(X+1, Y+1, delta);
		}
		else {
			int ans = 0;
			ans ^= query(X, Y);
			ans ^= query(X, y-1);
			ans ^= query(x-1, Y);
			ans ^= query(x-1, y-1);
			printf("%d\n", ans);
		}
	}
	return 0;
}