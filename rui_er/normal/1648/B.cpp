//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e6+5;

int T, n, c, a[N], tab[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int get(int l, int r) {
	chkmax(l, 0);
	chkmin(r, c);
	return tab[r] - tab[l-1];
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &c);
		rep(i, 1, c) tab[i] = 0;
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			++tab[a[i]];
		}
		rep(i, 1, c) tab[i] += tab[i-1];
		int ok = 1;
		rep(div, 1, c) {
			if(get(div, div)) continue;
			for(int i=1;i*div<=c;i++) {
//				printf("%d %d %d %d\n", div, i, i*div, i*(div+1)-1);
				ok &= !(get(i, i) && get(i*div, i*(div+1)-1));
			}
		}
		puts(ok?"Yes":"No");
	}
	return 0;
}