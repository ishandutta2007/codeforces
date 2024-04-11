#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 11;
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
char a[N][N];
int n,m,k;
void dfs(int l, int r)
{
    if (k==0) return;
    a[l][r]='.';
    k--;
    if (a[l+1][r]=='X') dfs(l+1,r);
    if (a[l-1][r]=='X') dfs(l-1,r);
    if (a[l][r+1]=='X') dfs(l,r+1);
    if (a[l][r-1]=='X') dfs(l,r-1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    int l,r;
    k=-k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='.') {l=i; r=j; k++; a[i][j]='X';}
        }
    dfs(l,r);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout<<a[i][j];
        cout<<endl;
    }
}