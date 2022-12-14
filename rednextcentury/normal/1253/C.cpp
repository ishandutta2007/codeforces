#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll pre[1000000];
ll dp[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for (int i=1;i<=m;i++)dp[i]=dp[i-1]+a[i], cout<<dp[i]<<' ';
    for (int i=m+1;i<=n;i++) {
        dp[i]=pre[i] + dp[i-m];
        cout<<dp[i]<<' ';
    }
    cout<<endl;
}