#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 11;
char a[N][N];
int use[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    int ans=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]=='P')
    {
        if (a[i-1][j]=='W')
        {
            ans-=use[i-1][j];
            use[i-1][j]=1;
            ans++;
        }
        if (a[i+1][j]=='W')
        {
            ans-=use[i+1][j];
            use[i+1][j]=1;
            ans++;
        }
        if (a[i][j-1]=='W')
        {
            ans-=use[i][j-1];
            use[i][j-1]=1;
            ans++;
        }
        if (a[i][j+1]=='W')
        {
            ans-=use[i][j+1];
            use[i][j+1]=1;
            ans++;
        }
    }
    cout<<ans<<endl;
}