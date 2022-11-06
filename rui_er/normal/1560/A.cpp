//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int T, n, ans[N], tot;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	rep(i, 1, 1666) {
		if(i % 3 == 0 || i % 10 == 3) continue;
		ans[++tot] = i;
		if(tot == 1000) break;
	}
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}