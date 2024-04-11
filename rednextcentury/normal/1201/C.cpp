#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int n,k;
bool check(long long X)
{
    long long num=0;
    for (int i=n/2;i<n;i++)
    {
        if (a[i]<X)num+=X-a[i];
        if (num>k)return 0;
    }
    return num<=k;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long l=0,r=2e9;
    long long ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if (check(mid))
            ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
}