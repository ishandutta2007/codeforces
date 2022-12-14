#include <bits/stdc++.h>
using namespace std;
map<int,int> mp[1000000];
int ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,m;
    cin>>n>>m;
    if (m>=n*(n-1)/2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a][b]=1;
        mp[b][a]=1;
    }
    for (int i=1;i<=n;i++)
        ret[i]=-1;
    bool ok=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (!mp[i][j])
            {
                ok=1;
                ret[i]=1;
                ret[j]=2;
                break;
            }
        }
        if (ok)break;
    }
    int cur=3;
    for (int i=1;i<=n;i++)
        if (ret[i]==-1)ret[i]=cur++;
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
    for (int i=1;i<=n;i++)
        cout<<((ret[i]==1)?2:ret[i])<<' ';
    cout<<endl;
}