//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N], s[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct LinearBasis {
	int p[31];
	void insert(int x) {
		per(i, 30, 0) {
			if(!((x >> i) & 1)) continue;
			if(!p[i]) {p[i] = x; return;}
			x ^= p[i];
		}
	}
}LB;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) s[i] = s[i-1] ^ a[i];
	if(!s[n]) return puts("-1")&0;
	rep(i, 1, n) LB.insert(s[i]);
	rep(i, 0, 30) if(LB.p[i]) ++ans;
	printf("%d\n", ans);
	return 0;
}