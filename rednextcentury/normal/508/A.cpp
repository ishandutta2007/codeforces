#include <bits/stdc++.h>
using namespace std;
bool a[1001][1001];
int tim[1001][1001];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        if (a[x][y]==0)
        tim[x][y]=i+1;
        a[x][y]=1;
    }
    int mn=10000000;
    for (int i=2;i<=n;i++)
    {
        for (int j=2;j<=m;j++)
        {
            if (a[i][j] && a[i][j-1] && a[i-1][j] && a[i-1][j-1])
            {
                mn=min(mn,max(tim[i][j],max(tim[i-1][j],max(tim[i][j-1],tim[i-1][j-1]))));
            }
        }
    }
    if (mn>k)
        cout<<0<<endl;
    else
    cout<<mn<<endl;
}