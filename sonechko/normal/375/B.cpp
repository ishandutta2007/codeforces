#include<bits/stdc++.h>
using namespace std;

#define pb push_back


const int N = 5000 + 11;

int a[N][N],kol[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char c;
        cin>>c;
        if (c=='1') a[i][j]=1;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=m; j>=1; j--)
            if (a[i][j]==1) kol[i][j]=kol[i][j+1]+1; else kol[i][j]=0;
    }
    int ans=0;
    for (int j=1; j<=m; j++)
    {
        vector<int> p;
        for (int i=1; i<=n; i++)
            p.pb(kol[i][j]);
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        for (int j=0; j<p.size(); j++)
            ans=max(ans,(j+1)*p[j]);
    }
    cout<<ans;
}