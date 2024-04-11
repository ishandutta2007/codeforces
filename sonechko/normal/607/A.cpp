#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;
pair<int,int> a[N];
int c[N],dp[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i].ff>>a[i].ss;
            a[i].ff++;
        }
    sort(a+1,a+n+1);
    int p=0;
    for (int i=0; i<=1000000; i++)
    {
        if (p<n&&a[p+1].ff==i) p++;
        c[i]=p;
    }
    dp[0]=0;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int p=max(0,a[i].ff-a[i].ss-1);
        dp[i]=dp[c[p]]+1;
        ans=max(ans,dp[i]);
    }
    cout<<n-ans<<endl;
}