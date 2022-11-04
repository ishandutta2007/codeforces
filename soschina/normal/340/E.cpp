#include <cstdio>
using namespace std;
const int MAXN = 2001;
const long long mod = 1000000007;

int n, vis[MAXN], a, b;
long long fac[MAXN] = {1}, inv[MAXN] = {0, 1}, facinv[MAXN] = {1}, ans;

long long C(int n, int m){
	return fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

int main(){
	scanf("%d", &n);
	for(long long i = 1; i <= n; i++){
		if(i != 1) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
		fac[i] = fac[i - 1] * i % mod;
		scanf("%d", &b);
		if(~b) vis[b]--;
		else vis[i]++, a++;
	}
	b = 0;
	for(int i = 1; i <= n; i++)
		if(vis[i] == 1) b++;
	ans = fac[a];
	for(int i = 1; i <= b; i++){
		ans += (i & 1 ? -1 : 1) * C(b, i) * fac[a - i];
		ans %= mod;
	}
	printf("%I64d", (ans % mod + mod) % mod);
}