//By: Luogu@rui_er(122461)
//test skipped code
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5, mod = 998244353;

int n, cnt_W, cnt_B, cnt__, cntPT, bkPT, bkBW, bkWB, fac[N], inv[N];
string s;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void initC(int lim) {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	rep(i, 2, lim) {
		fac[i] = 1LL * fac[i-1] * i % mod;
		inv[i] = 1LL * (mod - mod / i) * inv[mod%i] % mod;
	}
	rep(i, 2, lim) inv[i] = 1LL * inv[i-1] * inv[i] % mod;
}
int C(int x, int y) {
	if(y < 0 || x < y) return 0;
	return 1LL * fac[x] * inv[y] % mod * inv[x-y] % mod;
}
int qpow(int x, int y) {
	int ans = 1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y & 1) ans = 1LL * ans * x % mod;
	return ans;
}

int main() {
	initC(1000000);
	scanf("%d", &n);
	rep(i, 1, n) {
		cin>>s;
		if(s[0] == 'W' || s[1] == 'B') bkWB = 1;
		if(s[0] == 'B' || s[1] == 'W') bkBW = 1;
		if(s == "WB" || s == "BW") continue;
		else if(s == "?W" || s == "W?") ++cnt_W;
		else if(s == "?B" || s == "B?") ++cnt_B;
		else if(s == "??") ++cnt__;
		else if(s == "WW") ++cntPT, bkPT = 1;
		else if(s == "BB") --cntPT, bkPT = 1;
		else continue;
	}
//	printf("%d %d %d %d\n", cnt_W, cnt_B, cnt__, cntPT);
	int ans = C(cnt_W+cnt_B+2*cnt__, cnt_B+cnt__-cntPT);
//	printf("%d\n", ans);
	if(bkPT) return printf("%d\n", ans)&0;
	ans = (ans + mod - qpow(2, cnt__) + (2 - bkWB - bkBW)) % mod;
	printf("%d\n", ans);
    return 0;
}