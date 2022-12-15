#include<iostream>

using namespace std;

#define MOD 1000000009

string s;

long long power(long long base,long long e)
{
    if(e==0)return 1;

    long long res=1,p;

    if(e%2==1)
    {
        res*=base;
    }

    p=power(base,e/2);
    res*=p;
    res%=MOD;
    res*=p;
    res%=MOD;

    return res;
}

long long c(long long base,long long e)
{
    if(e==0)return 0;

    long long res=0,p;

    if(e%2==1)
    {

        res=power(base,e-1);
    }

    p=c(base,e/2);
    p*=power(base,e/2)+1;
    p%=MOD;
    res+=p;
    res%=MOD;

    //cout<<base<<" "<<e<<" "<<res<<endl;

    return res;
}

int main ()
{
    long long n,a,b,k,i,j,p=0,x,y;

    cin>>n>>a>>b>>k;

    cin>>s;

    for(j=0;j<k;j++)
    {
        if(s[j]=='+')x=1;
        else x=-1;

        y=x*power(a,n-j);
        y%=MOD;
        y*=power(b,j);
        y%=MOD;
        p+=y;
        p%=MOD;
    }

    x=power(a,MOD-2);
    x=power(x,k);
    x%=MOD;
    x*=power(b,k);
    x%=MOD;

    y=c(x,(n+1)/k);

    //cout<<x<<" "<<p<<" "<<y<<endl;

    y*=p;
    y%=MOD;

    while(y<0)y+=MOD;

    cout<<y<<endl;

    return 0;
}