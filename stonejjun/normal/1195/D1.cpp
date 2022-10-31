#include<bits/stdc++.h>
using namespace std;

long long int arr[101010];
long long int arr2[101010];

int main()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    for(i=1;i<=n;i++)
    {
        j=1;
        while(arr[i])
        {
            arr2[i]+=(arr[i]%10)*j;
            j*=100;
            arr[i]/=10;
        }
        arr2[i]=arr2[i]%998244353;
    }
    for(i=1;i<=n;i++)
    {
        ans+=arr2[i]*n*11;
        ans=ans%998244353;
    }
    printf("%lld",ans);
}