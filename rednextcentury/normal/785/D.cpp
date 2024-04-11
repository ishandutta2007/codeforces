#include <bits/stdc++.h>
using namespace std;
long long MOD=1000000007;
long long fact[1000000];
long long INV(long long a)
{
    long long b=MOD;
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
long long C(long long n,long long m)
{
    if (n==m)return 1;
    return (((fact[n]*INV(fact[m]))%MOD)*INV(fact[n-m]))%MOD;
}
long long Get(long long A,long long B)
{
    int a=-1,b=0;
    if (A>B)swap(A,B),swap(a,b);
    long long ret=C(A+B,A);
    A+=a,B+=b;
    ret=(ret-C(A+B,A)+MOD)%MOD;
    return ret;
}
long long A[1000000],B[1000000];
int main()
{
    fact[0]=1;
    for (int i=1;i<=300000;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    int n;
    string s;
    cin>>s;
    n=s.size();
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='(')
            A[i]=1;
        if (i>0)
            A[i]+=A[i-1];
    }
    for (int i=n-1;i>=0;i--)
    {
        if (s[i]==')')
            B[i]=1;
        if (i<n-1)
            B[i]+=B[i+1];
    }
    for (int i=0;i<n;i++)
        if (s[i]=='(')
            ret=(ret+Get(A[i],B[i+1]))%MOD;
    cout<<ret<<endl;
}