#include <cstdio>
using namespace std;
const int N = 500, MAXP = 1000, MAXN = 1e6 + 50;
const long long p = 1e9 + 7;

int q, x, y, num, len;
bool vis[MAXP + 1];
long long prime[MAXP + 1], inv[MAXN] = {0, 1}, fac[MAXN] = {1, 1}, facinv[MAXN] = {1, 1}, ans;

long long fastpow(long long base, long long fac = p - 2){
	long long ret = 1;
	do{
		if(fac & 1) ret = ret * base % p;
		base = base * base % p;
	}while(fac >>= 1);
	return ret;
}

int main(){
	for(long long i = 2; i < MAXN; i++){
		fac[i] = fac[i - 1] * i % p;
		inv[i] = (p - p / i) * inv[p % i] % p;
		facinv[i] = facinv[i - 1] * inv[i] % p;
	}
	for(int i = 2; i <= MAXP; i++) if(!vis[i]){
		prime[++len] = i;
		for(int j = i; j <= MAXP; j += i) vis[i] = true;
	}
	scanf("%d", &q);
	while(q--){
		ans = 1;
		scanf("%d%d", &x, &y);
		for(int i = 1; prime[i] * prime[i] <= x; i++) if(!(x % prime[i])){
			num = 0;
			do{
				num++;
				x /= prime[i];
			}while(!(x % prime[i]));
			ans = ans * fac[num + y - 1] % p * facinv[y - 1] % p * facinv[num] % p;
		}
		if(x != 1) ans = ans * y % p;
		ans = ans * fastpow(2, y - 1) % p;
		ans = (ans + p) % p;
		printf("%I64d\n", ans);
	}
	return 0;
}