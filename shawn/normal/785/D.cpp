#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)

const int maxn = 4e5 + 10;
typedef long long ll;

char s[maxn], ch[maxn];
ll fac[maxn], fac_inv[maxn], ans;
int L[maxn], R[maxn];
int n, tot;

int power(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = (1ll * ret * a) % mod;
		a = (1ll * a * a) % mod;
		b >>= 1;
	}
	return ret;
} 

int main() {
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	fac[0] = fac_inv[0] = 1;
	For(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
	fac_inv[n] = power(fac[n], mod - 2);
	Rep(i, n - 1, 1) fac_inv[i] = 1ll * fac_inv[i + 1] * (i + 1) % mod;
	s[0] = '#';
	For(i, 1, n) {
		s[++tot] = ch[i];
		s[++tot] = '#';
	}
	n = tot;
	For(i, 1, n) L[i] = L[i - 1] + (s[i] == '(');	
	Rep(i, n, 1) R[i] = R[i + 1] + (s[i] == ')');	
	for (int i = 2; i <= n; i += 2)
		if (s[i + 1] == ')'){
			ans = (ans + 1ll * (fac[L[i] + R[i] - 1] * fac_inv[L[i] - 1] % mod * fac_inv[R[i]] % mod)) % mod;
		}
	printf("%d", ans);
	return 0;
}