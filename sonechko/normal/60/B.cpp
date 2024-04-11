
#include<bits/stdc++.h>

using namespace std;
const int N = 10 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define y1 khdifkne
#define ll long long
#define ld long double
char a[N][N][N];
int ans,k,n,m;
bool use[N][N][N];
bool good(int lr, int l, int r)
{
    if (lr>=1&&l>=1&&r>=1&&lr<=k&&l<=n&&r<=m&&a[lr][l][r]=='.'&&use[lr][l][r]==0)
    return true;
    return false;
}
void dfs(int lr, int l, int r)
{
    ans++;
    use[lr][l][r]=1;
    if (good(lr+1,l,r)) dfs(lr+1,l,r);
    if (good(lr-1,l,r)) dfs(lr-1,l,r);
    if (good(lr,l-1,r)) dfs(lr,l-1,r);
    if (good(lr,l+1,r)) dfs(lr,l+1,r);
    if (good(lr,l,r-1)) dfs(lr,l,r-1);
    if (good(lr,l,r+1)) dfs(lr,l,r+1);
}
int main()
{
    cin>>k>>n>>m;
    for (int ij=1; ij<=k; ij++)
        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        cin>>a[ij][i][j];
    int x,y;
    cin>>x>>y;
    dfs(1,x,y);
    cout<<ans<<endl;
}