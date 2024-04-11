#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
ll dp1[N],a[N],mx1[N];
ll dp2[N],mx2[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        if (mx1[i-1]>=a[i]) mx1[i]=mx1[i-1]+1; else mx1[i]=a[i];
        dp1[i]=dp1[i-1]+mx1[i]-a[i];
    }
    for (int i=n; i>=1; i--)
    {
        if (mx2[i+1]>=a[i]) mx2[i]=mx2[i+1]+1; else mx2[i]=a[i];
        dp2[i]=dp2[i+1]+mx2[i]-a[i];
    }
    ll ans=2000000000000000000;
    for (int i=1; i<=n; i++)
    {
        ll tl=dp1[i-1]+dp2[i+1];
        ll d=max(a[i],max(mx1[i-1]+1,mx2[i+1]+1));
        ans=min(ans,tl+d-a[i]);
    }
    cout<<ans<<endl;
}