//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int T, n, a[N], s;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(int x) {
	for(int i=2;i*i<=x;i++) if(!(x % i)) return 1;
	return 0;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		s = 0;
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			s += a[i];
		}
		if(check(s)) {
			printf("%d\n", n);
			rep(i, 1, n) printf("%d%c", i, " \n"[i==n]);
		}
		else {
			rep(i, 1, n) {
				if(check(s-a[i])) {
					printf("%d\n", n-1);
					rep(j, 1, n) if(i != j) printf("%d ", j);
					puts("");
					break;
				}
			}
		}
	}
	return 0;
}