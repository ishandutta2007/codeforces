#include<iostream>
#include<map>

using namespace std;

#define MOD 1000000007

map<long long,long long> mp;

long long st(long long n)
{
    long long res;

    if(n==0)return 1;
    if(n==1)return 2;

    if(n%2==0)
    {
        res=st(n/2);
        res*=res;
        res%=MOD;
    }
    else
    {
        res=st(n/2);
        res*=res;
        res%=MOD;
        res*=2;
        res%=MOD;
    }

    return res;
}

long long f(long long n)
{
    if(n==1)return 1;
    if(mp[n])return mp[n];

    long long res=st(n-1),p;

    for(long long i=2;i*i<=n;i++)
    {
        if(i*i==n)
        {
            p=f(i);
            res-=p;
            while(res<0)res+=MOD;
        }
        else
        {
            if(n%i==0)
            {
                p=f(i);
                res-=p;
                while(res<0)res+=MOD;
                p=f(n/i);
                res-=p;
                while(res<0)res+=MOD;
            }
        }
    }

    res-=1;

    while(res<0)res+=MOD;

    mp[n]=res;

    return res;
}

int main ()
{
    long long x,y,i,res=0;

    cin>>x>>y;

    if(y%x!=0)
    {
        cout<<"0"<<endl;
        return 0;
    }

    cout<<f(y/x)<<endl;

    return 0;
}