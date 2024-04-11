#include <cstdio>
using namespace std;
const int N = 5001, p = 998244353;

int fpow(int base, int t = p - 2){
	int ret = 1;
	while(t){
		if(t & 1) ret = 1ll * ret * base % p;
		base = 1ll * base * base % p;
		t >>= 1;
	}
	return ret;
}

int n, k, fac[N] = {1}, facinv[N], ans;
char s[N];

int C(int n, int m){
	return 1ll * fac[n] * facinv[m] % p * facinv[n - m] % p;
}

int main(){
	scanf("%d%d%s", &n, &k, s);
	if(k == 0){
		putchar('1');
		return 0;
	}
	for(int i = 1; i <= n; i++)
		fac[i] = 1ll * i * fac[i - 1] % p;
	facinv[n] = fpow(fac[n]);
	for(int i = n; i > 0; i--)
		facinv[i - 1] = 1ll * facinv[i] * i % p;
	int l = 0, m = -1, r = -1, cntl = 0, cntr = 0;
	while(true){
		while(r + 1 < n && (s[r + 1] == '0' || cntr < k)){
			r++;
			if(s[r] == '1') cntr++;
		}
		if(cntr < k) break;
		ans = (((ans + C(r - l + 1, k)) % p - C(m - l + 1, cntl)) % p + p) % p;
		m = r;
		cntl = cntr;
		while(l < n){
			if(s[l] == '1'){
				cntl--;
				cntr--;
				l++;
				break;
			}
			l++;
		}
	}
	printf("%d", (ans + 1) % p);
	return 0;
}