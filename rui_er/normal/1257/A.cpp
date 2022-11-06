//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int T, n, x, a, b; 
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d%d", &n, &x, &a, &b);
		if(a > b) swap(a, b);
		int delta;
		delta = min(a-1, x);
		x -= delta; a -= delta;
		delta = min(n-b, x);
		x -= delta; b += delta;
		printf("%d\n", b-a);
	}
	return 0;
}