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
long long C(long long n,long long k)
{
    if (n<k)return 0;
    long long ret=1;
    for (long long i=n;i>n-k;i--)
        ret=(ret*(i%MOD))%MOD;
    long long b=1;
    for (long long i=k;i>1;i--)
        b=(b*i)%MOD;
    return (ret*mul_inv(b,MOD))%MOD;
}
long long a[1000];
int main()
{
    long long n,s;
    cin>>n>>s;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int tot=(1<<n)-1;
    long long ret=C(n+s-1,n-1);
    for (int i=1;i<=tot;i++)
    {
        long long S=s;
        int num=0;
        for (int j=0;j<n;j++)
            S-=(((1<<j)&i)>0)*(a[j]+1),num+=(((1<<j)&i)>0);
        if (num%2)
            ret=(ret-C(n+S-1,n-1)+MOD)%MOD;
        else
            ret=(ret+C(n+S-1,n-1))%MOD;
    }
    cout<<ret<<endl;
}