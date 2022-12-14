#include <bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > a[1000000];
int s[1001][1001];
int k;
int getSum(int i,int j)
{
    if (i<k || j<k)return 0;
    return s[i][j]-s[i-k][j]-s[i][j-k]+s[i-k][j-k];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n,m,q;
    cin>>n>>m>>k>>q;
    for (int i=0;i<q;i++)
        cin>>a[i].second.first>>a[i].second.second>>a[i].first;
    sort(a,a+q);
    int ret = -1;
    int l=0,r=q-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                s[i][j]=0;
        for (int i=0;i<=mid;i++)
            s[a[i].second.first][a[i].second.second]=1;
        int cur=a[mid].first;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                s[i][j]=s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        bool ok=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (getSum(i,j)==k*k)
                    ok=1;
                if (ok)break;
            }
            if (ok)break;
        }
        if (ok)ret=cur,r=mid-1;
        else l=mid+1;
    }
    cout<<ret<<endl;
}