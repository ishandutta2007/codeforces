//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, mod = 1e9+7;
const int pm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct LinearBasis {
	int p[19];
	LinearBasis() {memset(p, 0, sizeof(p));}
	~LinearBasis() {}
	void insert(int x) {
		per(i, 18, 0) {
			if(!((x >> i) & 1)) continue;
			if(!p[i]) {p[i] = x; return;}
			x ^= p[i];
		}
	}
	int qmax() {
		int ans = 0; 
		per(i, 18, 0) chkmax(ans, ans^p[i]);
		return ans;
	}
	int cnt() {
		int ans = 0;
		per(i, 18, 0) ans += !!p[i];
		return ans;
	}
}LB;
int qpow(int x, int y) {
	int ans = 1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y & 1) ans = 1LL * ans * x % mod;
	return ans;
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		int now = 0;
		per(j, 18, 0) {
			now <<= 1;
			while(!(a[i] % pm[j])) {
				now ^= 1;
				a[i] /= pm[j];
			}
		}
		LB.insert(now);
	}
	printf("%d\n", (qpow(2, n-LB.cnt())+mod-1)%mod);
    return 0;
}