#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll a[100005],b[100005],c[100005];
ll BS(ll w)
{
    ll left=1;
    ll right=n;
    ll mid,ans=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(w>c[mid])
            left=mid+1;
        else if(w<=c[mid])
        {
            ans=mid;
            right=mid-1;
        }
        //     else
        //       ans=mid;
        //   return ans;
    }
return ans;}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll sum=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum=sum+a[i];
        c[i]=sum;
    }
    ll m;
    cin>>m;
    for(int i=1; i<=m; i++)
        cin>>b[i];
    for(int i=1; i<=m; i++)
        cout<<BS(b[i])<<endl;

    return 0;
}