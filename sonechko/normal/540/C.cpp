#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;

const int N = 500 + 11;

char a[N][N];
int use[N][N],n,m;
bool dfs(int l, int r, int x, int y, int p)
{
          if (x==l&&y==r) return true;
          use[l][r]=p;
          if (l>1&&use[l-1][r]!=p&&a[l-1][r]=='.'&&dfs(l-1,r,x,y,p)) return true;
          if (l<n&&use[l+1][r]!=p&&a[l+1][r]=='.'&&dfs(l+1,r,x,y,p)) return true;
          if (r>1&&use[l][r-1]!=p&&a[l][r-1]=='.'&&dfs(l,r-1,x,y,p)) return true;
          if (r<m&&use[l][r+1]!=p&&a[l][r+1]=='.'&&dfs(l,r+1,x,y,p)) return true;
          return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    int l1,r1;
    int l2,r2;
    cin>>l1>>r1>>l2>>r2;
    if (l1==l2&&r1==r2) 
    {
              if (a[l1-1][r1]=='.') {cout<<"YES"<<endl; return 0;}
              if (a[l1+1][r1]=='.') {cout<<"YES"<<endl; return 0;}
              if (a[l1][r1-1]=='.') {cout<<"YES"<<endl; return 0;}
              if (a[l1][r1+1]=='.') {cout<<"YES"<<endl; return 0;}
              cout<<"NO"<<endl;
              return 0;
    }
    if (a[l2][r2]=='X')
    {
              a[l2][r2]='.';
              if (dfs(l1,r1,l2,r2,1)) {cout<<"YES"<<endl; return 0;} else
              {cout<<"NO"<<endl; return 0;}
    }
    if (a[l2-1][r2]=='.')
    {
              a[l2-1][r2]='X';
              if (dfs(l1,r1,l2,r2,2)) {cout<<"YES"<<endl; return 0;}
              a[l2-1][r2]='.';
    }
    if (a[l2+1][r2]=='.')
    {
              a[l2+1][r2]='X';
              if (dfs(l1,r1,l2,r2,3)) {cout<<"YES"<<endl; return 0;}
              a[l2+1][r2]='.';
    }
    if (a[l2][r2-1]=='.')
    {
              a[l2][r2-1]='X';
              if (dfs(l1,r1,l2,r2,4)) {cout<<"YES"<<endl; return 0;}
              a[l2][r2-1]='.';
    }
    if (a[l2][r2+1]=='.')
    {
              a[l2][r2+1]='X';
              if (dfs(l1,r1,l2,r2,5)) {cout<<"YES"<<endl; return 0;}
              a[l2][r2+1]='.';
    }
    cout<<"NO"<<endl;
}