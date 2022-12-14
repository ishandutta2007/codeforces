#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long mul_inv(long long a, long long b)
{
	long long b0 = b, t, q;
	long long x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
int main()
{
    long long j=mul_inv(2,MOD);
    long long n,k;
    scanf("%I64d%I64d",&k,&n);
    long long ans=0;
    long long h= min(n,k);
    for (long long i = 1; i <= h; i++)
    {
        long long t = k / i;
        long long  r = min(k / t, n);
        ans += ((k%MOD) * ((r - i + MOD +1)%MOD ) % MOD - (((((t%MOD) * (i + r) )%MOD* ((r - i + 1+MOD)%MOD)))%MOD * j)%MOD+MOD)%MOD;

        ans%=MOD;
        i = r;
    }
    if (n > k)
    {
        ans += ((k%MOD) * ((n - k)%MOD))%MOD,ans%=MOD;
    }
    printf("%I64d\n",ans);
}