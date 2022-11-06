//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5; 

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int pos = 0;
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			if(a[i] == n) pos = i;
		}
		if(pos > 1 && pos < n) puts("-1");
		else {
			per(i, n, 1) {
				if(i == pos) continue;
				printf("%d ", a[i]);
			}
			printf("%d\n", n);
		}
	}
	return 0;
}