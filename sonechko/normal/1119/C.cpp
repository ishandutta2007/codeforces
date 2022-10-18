#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 11;

int a[N][N],b[N][N];

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
        cin>>b[i][j];
    for (int i=1; i<n; i++)
    for (int j=1; j<m; j++)
    if (a[i][j]!=b[i][j])
    {
        a[i][j]=1-a[i][j];
        a[i+1][j]=1-a[i+1][j];
        a[i][j+1]=1-a[i][j+1];
        a[i+1][j+1]=1-a[i+1][j+1];
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]!=b[i][j]) {cout<<"No"; return 0;}
    cout<<"Yes";
}