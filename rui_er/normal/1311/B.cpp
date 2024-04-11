//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int T, n, m, a[N], b[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) b[i] = 0;
		rep(i, 1, m) {
			int x;
			scanf("%d", &x);
			b[x] = 1;
		}
		int L = 1, R = 1;
		while(L <= n) {
			while(R <= n && b[R]) ++R;
//			printf("[%d, %d]\n", L, R);
			sort(a+L, a+1+R);
			L = ++R;
		}
		int ok = 1;
		rep(i, 1, n-1) ok &= a[i] <= a[i+1];
		puts(ok?"YES":"NO");
	}
	return 0;
}