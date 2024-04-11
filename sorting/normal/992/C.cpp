#include<iostream>

using namespace std;

const long long mod=1000000007;

long long pow(long long base,long long e)
{
    if(e==0)
        return 1;

    long long res=1,p;

    if(e%2==1)
        res=base;

    p=pow(base,e/2);
    p*=p;
    p%=mod;
    res*=p;
    res%=mod;

    return res;
}

int main ()
{
    long long x,k,res,p;

    cin>>x>>k;

    if(x==0)
    {
        cout<<"0"<<endl;
        return 0;
    }

    p=pow(2,k);

    //cout<<p<<endl;

    x%=mod;

    res=x*p;
    res%=mod;
    res*=2;
    res%=mod;
    res-=p-1;
    res%=mod;

    while(res<0)
        res+=mod;

    cout<<res<<endl;

    return 0;
}