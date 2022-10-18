#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair

const int N = 2e5 + 11;

int dp[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    dp[0]=0;
    for (int i=1; i<=n; i++)
    if (a[i]==0) { dp[i]=min(n,i+k)-max(1,i-k)+1; cout<<dp[i]<<" ";} else
    {
        int t=a[i];
        int x=min(n,t+k);
        dp[i]=dp[t];
        int l=max(1,i-k);
        int r=min(n,i+k);
        dp[i]+=max(0,r-max(l,x+1)+1);
        cout<<dp[i]<<" ";
    }
}