#include<iostream>
#include<algorithm>

using namespace std;

long long a[100001];

int main ()
{
    long long n,i,res,k;

    cin>>n;

    for(i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);

    res=1;
    for(i=1;i<3;i++)
    {
        if(a[i]!=a[i-1])res=1;
        else res++;
    }
    k=res;
    for(i=3;i<n;i++)
    {
        if(a[i]!=a[i-1])break;
        res++;
    }
    if(k==2)
    {
        res=res*(res-1)/2;
    }
    if(k==3)
    {
        res=res*(res-1)*(res-2)/6;
    }
    cout<<res<<endl;

    return 0;
}