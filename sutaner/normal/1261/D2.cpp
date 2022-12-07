#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define pb push_back
#define maxn 400019
#define maxs
#define maxnode
#define ls ch[o][0]
#define rs ch[o][1]
#define M 998244353
#define Hash
#define Base 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define mem(x, v) memset(x, sizeof(x), v)
using namespace std;

int n, k;
int a[maxn];

ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}
inline ll get(int m, int n){
	if (m < n) return 0;
	return fac[m] * ifac[n] % M * ifac[m - n] % M;
}

ll power(int x, int y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}

int main(){
	init();
	scanf("%d%d", &n, &k);
	if (k == 1) {printf("0"); return 0;}
	int cnt = 0;
	rep(i, 1, n) scanf("%d", &a[i]); 
	a[n + 1] = a[1];
	rep(i, 1, n) if (a[i + 1] == a[i]) cnt++; 
	ll ans = 0;
	n -= cnt;
	ll inv2 = 499122177;
	srep(t, 0, n) ans = (ans + get(n, t) * power(k - 2, t) % M * (((n - t) & 1) ? power(2, n - t - 1) : ((power(2, n - t) + M - get(n - t, (n - t) >> 1)) * inv2 % M)) % M) % M;
	ans = ans * power(k, cnt) % M;
	printf("%lld", ans);
	return 0;
}