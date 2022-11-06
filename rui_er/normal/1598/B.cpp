//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int T, n, a[N][6], buc[6];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, 5) buc[i] = 0;
		rep(i, 1, n) rep(j, 1, 5) {
			scanf("%d", &a[i][j]);
			if(a[i][j]) ++buc[j];
		}
		int ok = 0;
		rep(i, 1, 5) rep(j, 1, 5) {
			if(i == j) continue;
			int tmp = 1, A = 0, B = 0, C = 0;
			rep(k, 1, n) {
				if(!a[k][i] && !a[k][j]) {tmp = 0; break;}
				if(a[k][i] && a[k][j]) ++C;
				else if(a[k][i]) ++A;
				else ++B;
			}
			if(tmp && A + C >= n / 2 && B + C >= n / 2) {ok = 1; break;}
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}