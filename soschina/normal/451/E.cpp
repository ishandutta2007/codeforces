#include <cstdio>
using namespace std;
const int MAXN = 21;
const long long p = 1e9 + 7;

long long fpow(long long base, int pow = p - 2){
	long long ret = 1;
	while(pow){
		if(pow & 1) ret = ret * base % p;
		base = base * base % p;
		pow >>= 1;
	}
	return ret;
}

long long C(long long n, long long m){
	long long a = 1, b = 1;
	for(long long i = 1; i <= m; i++){
		b = b * i % p;
		a = a * (n - i + 1) % p;
	}
	return a * fpow(b) % p;
}

long long lucas(long long n, long long m){
	if(!m) return 1;
	return lucas(n / p, m / p) * C(n % p, m % p) % p;
}

bool rev;
long long n, s, num[MAXN], ans;

void dfs(int i){
	if(i == n){
		ans += (rev ? -1 : 1) * lucas(s + n - 1, n - 1);
		ans %= p;
		return;
	}
	i++;
	if(num[i] < s){
		rev ^= 1;
		s -= num[i] + 1;
		dfs(i);
		rev ^= 1;
		s += num[i] + 1;
	}
	dfs(i);
}

int main(){
	scanf("%d%I64d", &n, &s);
	for(int i = 1; i <= n; i++)
		scanf("%I64d", num + i);
	dfs(0);
	printf("%I64d", (ans + p) % p);
}