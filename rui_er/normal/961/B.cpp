//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, k, a[N], t[N], sum, ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &t[i]);
	rep(i, 1, n) sum += a[i] * t[i];
	int now = 0;
	rep(i, 1, k-1) now += (!t[i]) * a[i];
	rep(L, 1, n) {
		int R = L + k - 1;
		if(R > n) break;
		if(!t[R]) now += a[R];
		if(L > 1 && !t[L-1]) now -= a[L-1];
		chkmax(ans, sum+now);
	}
	printf("%d\n", ans);
	return 0;
}