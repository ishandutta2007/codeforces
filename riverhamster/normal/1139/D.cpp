#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const ll mod = 1000000007, N = 100005, DIV = 258, FAC = 10;
ll qp(ll x, int y){
	ll ans = 1;
	for(; y; y>>=1, x = (x * x) % mod) if(y & 1) ans = (ans * x) % mod;
	return ans;
}
#define inv(x) qp((x), mod-2)
ll f[N];
int d[N][DIV], dc[N], fac[N][FAC], fc[N], p[N], ps = 0, n;
bool np[N];

void pre(int n){
	for(int i=2; i<=n; ++i){
		if(!np[i]){
			p[++ps] = i;
			fc[i] = 1; fac[i][0] = i;
			for(int j=i*2; j<=n; j+=i)
				np[j] = true, fac[j][fc[j]++] = i;
		}
	}
}
ll cal(int x, int y){ //sum[gcd(x, i) == y] such that 1 <= i <= n, y | x
	// printf("cal(%d, %d) = ", x, y);
	// puts("");
	x /= y;
	int nn = n / y, s, pos = 1;
	ll ans = 0;
	// printf("now fc[%d] = %d\n", x, fc[x]);
	for(int i=1; i<(1 << (fc[x])); i++){
		s = 1; pos = -1;
		for(int j=0; j<fc[x]; j++)
			if(i & (1 << j)) pos = -pos, s *= fac[x][j];
		ans += pos * (nn / s);
	}
	// printf("%lld\n", nn - ans);
	return nn - ans;
}

int main(){
	// File("cf1139d");
	in(n);
	pre(n);
	f[1] = 0;
	ll s = 0, invn = inv(n);
	for(int i=1; i<=n; i++)
		for(int j=i*2; j<=n; j+=i)
			d[j][++dc[j]] = i;
	for(int i=2; i<=n; i++){
		for(int j=1; j<=dc[i]; j++)
			f[i] = (f[i] + f[d[i][j]] * cal(i, d[i][j]) % mod) % mod;
		f[i] = (f[i] * invn % mod + 1) % mod * n % mod * inv(n - n / i) % mod;
		// printf("f[%d] = %lld\n", i, f[i]);
	}
	for(int i=1; i<=n; i++){
		s += f[i];
		if(s >= mod) s -= mod;
	}
	printf("%lld\n", (s * invn % mod + 1) % mod);
	return 0;
}