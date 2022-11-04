#include <cstdio>
using namespace std;
const int p = 998244353;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int q, C[51][51] = {1}, cnt[14], len;
long long d, u, v, prime[14];

int solve(long long n){
	int s = 0, ret = 1;
	for(int i = 0; i < len; i++){
		cnt[i] = 0;
		while(n % prime[i] == 0) n /= prime[i], cnt[i]++;
		s += cnt[i];
	}
	for(int i = 0; i < len; i++)
		ret = 1ll * ret * C[s][cnt[i]] % p, s -= cnt[i];
	return ret;
}

int main(){
	for(int i = 1; i < 51; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	scanf("%lld%d", &d, &q);
	for(int i = 2; 1ll * i * i <= d; i++) if(d % i == 0){
		prime[len++] = i;
		do d /= i; while(d % i == 0);
	}
	if(d != 1) prime[len++] = d;
	while(q--){
		scanf("%lld%lld", &u, &v);
		d = gcd(u, v);
		printf("%lld\n", 1ll * solve(u / d) * solve(v / d) % p);
	}
	return 0;
}