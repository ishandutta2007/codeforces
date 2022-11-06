//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e6+5; 

int n, cnt[4], a[N], b[N], nowA, nowB;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n); n <<= 1;
	rep(i, 1, n) scanf("%1d", &a[i]);
	rep(i, 1, n) scanf("%1d", &b[i]);
	rep(i, 1, n) ++cnt[a[i]<<1|b[i]];
	rep(i, 1, n) {
		per(j, 3, 0) {
			if(cnt[j]) {
				a[i] = j >> 1;
				b[i] = j & 1;
				--cnt[j];
				break;
			}
		}
	}
	rep(i, 1, n) {
		if(i & 1) nowA += a[i];
		else nowB += b[i];
	}
	puts(nowA>nowB?"First":nowA<nowB?"Second":"Draw");
    return 0;
}