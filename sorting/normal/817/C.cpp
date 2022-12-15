#include<iostream>

using namespace std;

long long n,s;

bool if_big(long long x)
{
    long long p=x;

    while(p>0)
    {
        x-=p%10;
        p/=10;
    }

    if(x>=s)return 1;

    return 0;
}

int main ()
{
    long long i,res=0,p;

    cin>>n>>s;

    if(n>s+162)p=s+162;
    else p=n;

    for(i=s;i<=p;i++)
    {
        if(if_big(i)==1)res++;
    }

    res+=n-p;

    cout<<res<<endl;

    return 0;
}