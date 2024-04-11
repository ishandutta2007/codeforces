#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[105][10031];
int closest[104][10031];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)cin>>a[i][j];
    for (int i=1;i<=n;i++){
        int last = 0;
        int first=-1;
        for (int j=1;j<=m;j++) {
            if (a[i][j]=='1') last = j;
            if (a[i][j]=='1' && first==-1)first = j;
            closest[i][j]=1e9;
            if (last!=0)
            closest[i][j]=min(closest[i][j], j-last);
            if (first!=-1)
            closest[i][j]=min(closest[i][j], first+m-j);
        }
        last=0,first=-1;
        for (int j=m;j>=1;j--) {
            if (a[i][j]=='1') last = j;
            if (a[i][j]=='1' && first==-1)first = j;
            if (last!=0)
                closest[i][j]=min(closest[i][j], last-j);
            if (first!=-1)
                closest[i][j]=min(closest[i][j], m-first+j);
        }
    }
    ll ret=1e18;
    for (int i=1;i<=m;i++){
        ll cost=0;
        for (int j=1;j<=n;j++)cost+=closest[j][i];
        ret=min(ret,cost);
    }
    if (ret>=1e9)cout<<-1<<endl;
    else cout<<ret<<endl;
}