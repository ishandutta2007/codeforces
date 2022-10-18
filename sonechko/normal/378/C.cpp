#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
const int N = 500 + 11;

char a[N][N];
bool use[N][N];
int kol;

void dfs(int l, int r)
{
    if (kol==0) return;
    kol--;
    a[l][r]='X';
    if (a[l-1][r]=='.') dfs(l-1,r);
    if (a[l+1][r]=='.') dfs(l+1,r);
    if (a[l][r-1]=='.') dfs(l,r-1);
    if (a[l][r+1]=='.') dfs(l,r+1);
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        if (a[i][j]=='.') kol++;
    }
    kol-=k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        if (a[i][j]=='.') dfs(i,j);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (a[i][j]=='.')cout<<'X'; else
            if (a[i][j]=='X')cout<<'.'; else
            cout<<a[i][j];
        cout<<endl;
    }
}