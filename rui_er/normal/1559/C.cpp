//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e4+5;

int T, n, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		if(a[1]) {
			printf("%d ", n+1);
			rep(i, 1, n) printf("%d%c", i, " \n"[i==n]);
		}
		else if(!a[n]) {
			rep(i, 1, n) printf("%d ", i);
			printf("%d\n", n+1);
		}
		else {
			int pos = 0;
			rep(i, 1, n-1) if(!a[i] && a[i+1]) {pos = i; break;}
			if(!pos) {puts("-1"); continue;}
			rep(i, 1, pos) printf("%d ", i);
			printf("%d ", n+1);
			rep(i, pos+1, n) printf("%d ", i);
			puts("");
		}
	}
	return 0;
}