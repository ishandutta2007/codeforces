#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int b[1000][1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    bool ok=1;
    vector<pair<int,int> > vec;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1)
            {
                b[i][j]=1,b[i+1][j]=1;
                b[i][j+1]=1,b[i+1][j+1]=1;
                if (i+1>n || j+1>m)ok=0;
                vec.push_back({i,j});
            }
            if (a[i][j]==0 && b[i][j]==1)ok=0;
            if (a[i][j]==1 && b[i][j]==0)ok=0;
        }
    }
    if (ok)
    {
        cout<<vec.size()<<endl;
        for (auto x:vec)
            cout<<x.first<<' '<<x.second<<endl;
    }
    else cout<<-1<<endl;
}