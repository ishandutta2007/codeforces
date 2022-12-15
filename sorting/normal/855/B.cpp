#include<iostream>

using namespace std;

#define MINI -3000000000000000000

long long n,p,q,r,a[100001];

int main()
{
    cin>>n>>p>>q>>r;

    long long k=n-1,maxi1=MINI,maxi2=MINI,res=MINI;

    for(k=0;k<n;k++)cin>>a[k];


    k=n-1;
    while(k>=0)
    {
        maxi1=max(maxi1,r*a[k]);
        maxi2=max(maxi2,maxi1+q*a[k]);
        res=max(res,maxi2+p*a[k]);
        k--;
    }

    cout<<res<<endl;

    return 0;
}