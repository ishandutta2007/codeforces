#include <cstdio>
using namespace std;
const int N = 10;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int t, len;
long long a, m, d, l, r, prime[N], ans;

long long f(int n, int i = 0, long long pd = 1){
	if(!n) return r / pd - l / pd;
	long long ret = 0;
	for(; i + n <= len; i++)
		ret += f(n - 1, i + 1, pd * prime[i]);
	return ret;
}

int main(){
	scanf("%d", &t);
	while(t--){
		len = 0;
		scanf("%lld%lld", &a, &m);
		d = gcd(a, m);
		l = a / d - 1, r = (a + m) / d - 1;
		ans = r - l;
		m /= d;
		for(long long i = 2; i * i <= m; i++) if(m % i == 0){
			prime[len++] = i;
			do m /= i; while(m % i == 0);
		}
		if(m > 1) prime[len++] = m;
		for(int i = 1; i <= len; i++)
			ans += (i & 1 ? -1 : 1) * f(i);
		printf("%lld\n", ans);
	}
	return 0;
}