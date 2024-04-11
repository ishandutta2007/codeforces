//luogu@rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int T, n, m;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
int calc_greedy(int n, int m) {
	int ans = 0;
	per(i, 30, 0) {
		int x = (n >> i) & 1;
		int y = (m >> i) & 1;
		if(x && !y) break;
		if(y && !x) ans += 1 << i;
	}
	return ans;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", calc_greedy(n, m+1));
	}
	return 0;
}