//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e3+5;

ll n, m, a[N], b[N], k, sa[N], sb[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, m) scanf("%lld", &b[i]);
	scanf("%lld", &k);
	rep(i, 1, n) a[i] += a[i-1];
	rep(i, 1, m) b[i] += b[i-1];
	memset(sa, 0x3f, sizeof(sa));
	memset(sb, 0x3f, sizeof(sb));
	rep(L, 1, n) rep(R, L, n) chkmin(sa[R-L+1], a[R]-a[L-1]);
	rep(L, 1, m) rep(R, L, m) chkmin(sb[R-L+1], b[R]-b[L-1]);
	rep(i, 1, n) rep(j, 1, m) if(sa[i] * sb[j] <= k) chkmax(ans, i*j);
	printf("%lld\n", ans);
	return 0;
}