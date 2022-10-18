#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

int a[N],dp1[N],dp2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]>a[i-1]) dp1[i]=dp1[i-1]+1;
        else dp1[i]=1;
    }
    for (int i=n; i>=1; i--)
    {
        if (a[i+1]>a[i]) dp2[i]=dp2[i+1]+1;
        else dp2[i]=1;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        ans=max(ans,dp2[i]);
        if (a[i+1]>a[i-1]) ans=max(ans,dp2[i+1]+dp1[i-1]);
    }
    cout<<ans;
}