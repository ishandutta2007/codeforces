#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 100 + 11;
int ans,n;
int a[N][N],use[N];
void dfs(int l, int r)
{
    ans=max(ans,r);use[l]=1;
    for (int j=1; j<=n; j++)
        if (use[j]==0&&a[l][j]!=0) dfs(j,r+a[l][j]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        a[l][r]=k;
        a[r][l]=k;
    }
    dfs(0,0);
    cout<<ans<<endl;
}