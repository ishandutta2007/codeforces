#include<bits/stdc++.h>
using namespace std;
pair<int,int> hate[1000000];
struct node
{
    long long val;
    long long X;
    long long Y;
    int id;
};
long long x[1000000];
long long y[1000000];
bool operator<(node a,node b)
{
    return a.val<b.val;
}
node a[1000000];
long long ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].X>>a[i].Y;
        x[i]=a[i].X,y[i]=a[i].Y;
        a[i].val = a[i].X-a[i].Y;
        a[i].id = i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        a[i].X+=a[i-1].X;
        a[i].Y+=a[i-1].Y;
    }
    for (int i=1;i<=n;i++)
    {
        ret[a[i].id]+=(a[i].Y-a[i-1].Y)*(i-1)+a[i-1].X;
        ret[a[i].id]+=(a[i].X-a[i-1].X)*(n-i)+a[n].Y-a[i].Y;
    }
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        long long best = min(x[u]+y[v],x[v]+y[u]);
        ret[u]-=best;
        ret[v]-=best;
    }
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
}