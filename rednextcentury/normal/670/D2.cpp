#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long a[1000001];
long long b[1000001];
long long n,k;
bool check(ll m)
{
    ll need=0;
    for (int i=0;i<n;i++)
    {
        need+=max(0LL,b[i]*m-a[i]);
        if (need>k)return 0;
        
    }
    return need<=k;
}
long long bs(long long l,long long r)
{
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>b[i];

    for (int i=0;i<n;i++)
        cin>>a[i];
    cout<<bs(0,2000000000)<<endl;
}