#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define y1 skfn

const int N = 1000 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

char a[N][N],b[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        b[i][j]='.';
    }
    for (int i=1; i<=n-2; i++)
    for (int j=1; j<=m-2; j++)
        if (a[i][j]=='#'&&a[i][j+1]=='#'&&a[i][j+2]=='#'&&
            a[i+1][j]=='#'&&a[i+1][j+2]=='#'&&
            a[i+2][j]=='#'&&a[i+2][j+1]=='#'&&a[i+2][j+2]=='#')
    {
        b[i][j]='#';
        b[i][j+1]='#';
        b[i][j+2]='#';
        b[i+1][j]='#';
        b[i+1][j+2]='#';
        b[i+2][j]='#';
        b[i+2][j+1]='#';
        b[i+2][j+2]='#';
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]!=b[i][j]) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
}