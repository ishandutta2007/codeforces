#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2000020
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int power(int x, int y) {
	int ans = 1, con = x;
	while (y) {
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x) {
	return power(x, M - 2);
}

int n, m, a[maxn], f[maxn];
void init(){
	f[0] = f[1] = 19260817; //XXX
	srep(i, 1, m) {
		f[i + 1] = (1ll * (m + 1ll * i * n % M + 2ll * (M - i)) * f[i] % M + 1ll * (M - 1ll * i * (n - 1) % M * f[i - 1] % M) + 1ll * (M - 1ll * i * (n - 1) % M)) % M;
		f[i + 1] = 1ll * f[i + 1] * getinv(m - i) % M;
	}
	int res = 0;
	rep(i, 1, n) res += f[a[i]], mo(res); res += M - (1ll * (n - 1) * f[1] % M + f[m]) % M, mo(res);
	printf("%d", res);
}


int main(){
	scanf("%d", &n); rep(i, 1, n) scanf("%d", a + i), m += a[i];
	init();
	return 0;
}