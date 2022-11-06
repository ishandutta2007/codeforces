//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int T, l, r;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
int calc(int x) {
	int ans = 0;
	for(;x;x/=10) ans += x;
	return ans;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", calc(r)-calc(l));
	}
	return 0;
}