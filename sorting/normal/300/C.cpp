#include<iostream>

#define endl "\n"
#define MOD 1000000007

using namespace std;

long long fact[1000001],a,b;

bool check(long long p)
{
    long long k;

    while(p>=10)
    {
        k=p%10;
        if(k!=a && k!=b)return 0;
        p/=10;
    }

    if(p!=a && p!=b)return 0;
    return 1;
}

long long binpow(long long a,long long k)
{
    //cout<<a<<" "<<k<<endl;
    if(k==0)return 1;
    if(k&1)return (a*(binpow(a,k-1)))%MOD;
    long long res=binpow(a,k>>1)%MOD;
    //cout<<(res*res)%MOD<<" a "<<k<<endl;
    return (res*res)%MOD;
}

int main  ()
{
    long long n,i,res=0;

    ios::sync_with_stdio(false);

    cin>>a>>b>>n;

    fact[0]=1;
    for(i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%MOD;

    for(i=0;i<=n;i++)
    {
        if(check(i*a+(n-i)*b)==1)
        {
            //cout<<i<<endl;
        //cout<<binpow((fact[i]*fact[n-i])%MOD,MOD-2)<<endl;
            res=(res+(fact[n]*binpow((fact[i]*fact[n-i])%MOD,MOD-2))%MOD)%MOD;
        }
    }

    cout<<res<<endl;

    return 0;
}