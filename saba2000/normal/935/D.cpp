#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long in[2000009];
long long a[10000009],b[10000009];
long long exp(long long n, long long e)
{
    if(e==0) return 1;
    if(e%2==1)
    {
        return n*exp(n,e-1)%mod;
    }
    else
    {
        long long x=exp(n,e/2);
        return x*x%mod;
    }
}
main()
{
    long long n,m;
    cin >> n >> m;
    for (long long i=0 ;i<=200000; i++)
        in[i]=exp(i,mod-2);
        //cout<<i<<" "<<in[i]<<endl;
    for (long long i=0 ; i < n ;i++)
    {
        cin >> a[i];
    }
    for (long long j = 0; j < n; j++)
    {
        cin >> b[j];
    }
    long long ans=0,P =1;
    for (long long i =0 ;i < n; i++)
    {
        if(a[i]!=0 && b[i]!=0 && a[i]<b[i]) break;
        if(a[i]!=0 && b[i]!=0 && a[i]>b[i])
        {
            ans=(ans+P)%mod;
            break;
        }
        else
            if(a[i]!=0 && b[i]!=0 && a[i]==b[i])
                continue;
        else
        if(a[i]==0 && b[i]==0)
        {
            ans=(ans+P*m%mod*(m-1)%mod*in[2]%mod*in[m]%mod*in[m]%mod)%mod;
            P =P*in[m]%mod;
        }
        else
        if(a[i] ==0)
        {
            ans =(ans+P*(m-b[i])%mod*in[m]%mod)%mod;
            P=P*in[m]%mod;
        }
        else
        if(b[i]==0)
        {
            ans=(ans+P*(a[i]-1)%mod*in[m]%mod)%mod;
            P=P*in[m]%mod;
        }
    }
    cout << ans << endl;
}