#include<iostream>
#include<algorithm>

#define mod 1000000007

using namespace std;

long long  x[300001],res,sum1[300001],sum2[300001];

const long long one=1;

int main ()
{
    long long n,i,j,k,p,t;

    ios::sync_with_stdio(false);

    cin>>n;

    t=n/2;

    for(i=0;i<n;i++)
    {
        cin>>x[i];
    }

    sort(x,x+n);

    sum1[0]=x[0];

    for(i=1;i<n;i++)
    {
        sum1[i]=sum1[i-1]+x[i];
        //cout<<sum1[i]<<" "<<i<<endl;
    }

    //cout<<"ok"<<endl;

    sum2[n-1]=x[n-1];

    for(i=n-2;i>=0;i--)
    {
        //cout<<"ok"<<endl;
        sum2[i]=sum2[i+1]+x[i];
    }

    //st[0]=1;
    //for(i=1;i<=32;i++)st[i]=st[i-1]<<1;
    //cout<<"ok"<<endl;

    for(i=n-1;i>1;i--)
    {
        p=0;
        if(i>=t)k=n-i;
        else k=i;
        if(k!=0)p=sum2[n-k]-sum1[k-1];

        //cout<<p<<endl;

        res+=p;

        res=res<<1;
        if(res>=mod)res%=mod;
        while(res<0)res+=mod;
    }

    p=0;
    if(i>=t)k=n-i;
    else k=i;
    if(k!=0)p=sum2[n-k]-sum1[k-1];

    //cout<<p<<endl;

    res+=p;
    if(res>=mod)res%=mod;
    while(res<0)res+=mod;

    cout<<res<<endl;

    return 0;
}