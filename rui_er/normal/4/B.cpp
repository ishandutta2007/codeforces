//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 35;

int d, T, a[N], b[N], mn, mx;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &d, &T);
	rep(i, 1, d) {
		scanf("%d%d", &a[i], &b[i]);
		mn += a[i]; mx += b[i];
	}
	if(T < mn || T > mx) return puts("NO")&0;
	puts("YES");
	rep(i, 1, d) T -= a[i];
	rep(i, 1, d) {
		int delta = min(T, b[i]-a[i]);
		a[i] += delta; T -= delta;
		if(!T) break;
	}
	rep(i, 1, d) printf("%d%c", a[i], " \n"[i==d]);
	return 0;
}