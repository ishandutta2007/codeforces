#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[1000][1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int ret=0,cost=0;
    for (int j=1;j<=m;j++)
    {
        int mx=0,mn=0;
        int cur=0;
        for (int i=1;i<=n;i++)
        {
            int num=0;
            for (int x=i;x<=min(i+k-1,n);x++)
                if (a[x][j]==1)num++;
            if (num>mx)
                mx=num,mn=cur;
            cur+=a[i][j];
        }
        ret+=mx;
        cost+=mn;
    }
    cout<<ret<<' '<<cost<<endl;
}