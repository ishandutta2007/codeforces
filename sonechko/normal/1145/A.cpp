#include<bits/stdc++.h>
using namespace std;

const int N = 20 + 11;

int a[N],dp[N][N];
int ans;

bool sortt(int l, int r)
{
    for (int j=l+1; j<=r; j++)
        if (a[j]<a[j-1]) return false;
    return true;
}

void dfs(int l, int r)
{
    if (dp[l][r]) return;
    if (sortt(l,r)) {ans=max(ans,r-l+1); return;}
    int mid=(l+r)/2;
    dfs(l,mid);
    dfs(mid+1,r);
    dp[l][r]=1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    dfs(1,n);
    cout<<ans<<endl;
}