#include<iostream>

using namespace std;

long long  a[200001],b[200001],c[200001],d[200001];

int main ()
{
    long long n,k,i,res=0,num,num2,p;
    ios::sync_with_stdio(false);



    cin>>n>>k;

    for(i=0;i<n;i++)cin>>a[i];
    for(i=k-1;i>=0;i--)
    {
        b[0]+=a[i];
    }

    for(i=1;i<=n-k;i++)
    {
        b[i]=a[i+k-1]-a[i-1]+b[i-1];

    }
    c[n-k]=b[n-k];
    d[n-k]=n-k;
    //cout<<c[n-k]<<" "<<n-k<<endl;
    for(i=n-k-1;i>=k;i--)
    {
        if(b[i]>=c[i+1])
        {
            d[i]=i;
            c[i]=b[i];
        }
        else
        {
            d[i]=d[i+1];
            c[i]=c[i+1];
        }
        //cout<<c[i]<<" "<<i<<endl;
    }

    for(i=0;i<=n-2*k;i++)
    {
        p=b[i]+c[i+k];
        if(p>res)
        {
            res=p;
            num=i+1;
            num2=d[i+k]+1;
        }
    }

    cout<<num<<" "<<num2<<endl;

    return 0;
}