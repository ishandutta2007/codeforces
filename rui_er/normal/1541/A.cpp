//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int T, n; 
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int now = 1;
		if(n & 1) {
			printf("2 3 1 ");
			now = 4;
		}
		for(;now<=n;now+=2) printf("%d %d ", now+1, now);
		puts("");
	}
	return 0;
}