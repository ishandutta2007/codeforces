//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N], lg[N], st[N][19], ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int gcd(int L, int R) {
	int k = lg[R-L+1] - 1;
	return __gcd(st[L][k], st[R-(1<<k)+1][k]);
}

int main() {
	rep(i, 1, N-1) lg[i] = lg[i-1] + ((1 << lg[i-1]) == i);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) st[i][0] = a[i];
	rep(j, 1, 18) {
		rep(i, 1, n-(1<<j)+1) {
			st[i][j] = __gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
	rep(i, 1, n) {
		int L = 1, R = i, x = 0;
		while(R - L >= 5) {
			int M = (L + R) >> 1;
			if(gcd(M, i) == i - M + 1) {x = M; break;}
			if(gcd(M, i) > i - M + 1) R = M - 1;
			else L = M + 1;
		}
		if(!x) {
			rep(j, L, R) {
				if(gcd(j, i) == i - j + 1) {
					x = j;
					break;
				}
			}
		}
		ans[i] = ans[i-1];
//		printf("%d\n", x);
		if(x) chkmax(ans[i], ans[x-1] + 1);
	}
	rep(i, 1, n) printf("%d%c", ans[i], " \n"[i==n]);
	return 0;
}