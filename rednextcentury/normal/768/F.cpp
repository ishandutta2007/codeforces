#include<bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
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
    return (((fact[n]*INV(fact[m]))%MOD)*INV(fact[n-m]))%MOD;
}
int main()
{
    fact[0]=1;
    for (int i=1;i<=300000;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    long long f,w,h;
    cin>>f>>w>>h;
    h++;
    long long tot=0;
    long long ok=0;
    if (f==0)
    {
        if (w>=h)
            tot=ok=1;
        else
            tot=1,ok=0;
    }
    else if (w==0)
    {
        ok=1,tot=1;
    }
    else
    {
        for (long long i=1;i<=f;i++)
        {
            for (long long j=i-1;j<=i+1;j++)
            {
                if (j<1)continue;
                long long Wl=w-j*h;
                long long Fl=f-i;
                long long Wl2=w-j;
                if (Wl2>=0)
                    tot+=((C(Fl+i-1,i-1)*C(Wl2+j-1,j-1))%MOD)*(1+(i==j)),tot%=MOD;
                if (Wl>=0)
                    ok+=((C(Fl+i-1,i-1)*C(Wl+j-1,j-1))%MOD)*(1+(i==j)),ok%=MOD;
            }
        }
    }
    cout<<(ok*INV(tot))%MOD<<endl;
}