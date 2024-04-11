#include <cstdio>
using namespace std;
const int N = 2e5 + 1, p = 998244353;

int t, n, x, val1, val2, cnt1, cnt2, fac[N] = {1};

inline int fpow(int base, int t = p - 2){
	int ret = 1;
	while(t){
		if(t & 1) ret = 1ll * ret * base % p;
		base = 1ll * base * base % p;
		t >>= 1;
	}
	return ret;
}

int C(int n, int m){
	return 1ll * fac[n] * fpow(fac[m]) % p * fpow(fac[n - m]) % p;
}

int main(){
	for(int i = 1; i < N; i++)
		fac[i] = 1ll * fac[i - 1] * i % p;
	scanf("%d", &t);
	while(t--){
		val1 = val2 = cnt1 = cnt2 = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &x);
			if(x > val1){
				val2 = val1;
				cnt2 = cnt1;
				val1 = x;
				cnt1 = 1;
			}else if(x == val1) cnt1++;
			else if(x > val2){
				val2 = x;
				cnt2 = 1;
			}else if(x == val2) cnt2++;
		}
		if(cnt1 > 1){
			printf("%d\n", fac[n]);
			continue;
		}
		if(val1 - val2 > 1){
			puts("0");
			continue;
		}
		printf("%d\n", 1ll * C(cnt1 + cnt2 - 1, cnt1) * C(n, cnt1 + cnt2) % p * fac[cnt1] % p * fac[cnt2] % p * fac[n - cnt1 - cnt2] % p);
	}
}