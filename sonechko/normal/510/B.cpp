#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 5e1 + 11;
///-----------------------------------------------------------
int use[N][N];
char a[N][N];
///-----------------------------------------------------------
void dfs(int l, int r, int l1, int r1)
{
    use[l][r]=1;
    if (a[l-1][r]==a[l][r]&&(l-1!=l1||r!=r1))
    {
        if (use[l-1][r]==1) {cout<<"Yes"<<endl; exit(0);}
        dfs(l-1,r,l,r);
    }
    if (a[l+1][r]==a[l][r]&&(l+1!=l1||r!=r1))
    {
        if (use[l+1][r]==1) {cout<<"Yes"<<endl; exit(0);}
        dfs(l+1,r,l,r);
    }
    if (a[l][r-1]==a[l][r]&&(l!=l1||r-1!=r1))
    {
        if (use[l][r-1]==1) {cout<<"Yes"<<endl; exit(0);}
        dfs(l,r-1,l,r);
    }
    if (a[l][r+1]==a[l][r]&&(l!=l1||r+1!=r1))
    {
        if (use[l][r+1]==1) {cout<<"Yes"<<endl; exit(0);}
        dfs(l,r+1,l,r);
    }
}
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        cin>>a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        if (use[i][j]==0) dfs(i,j,-1,-1);
    cout<<"No"<<endl;
}