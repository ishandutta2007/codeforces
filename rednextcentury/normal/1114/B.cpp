#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
pair<long long,int> b[1000001];
bool vis[1000001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i],b[i]={a[i],i};
    sort(b+1,b+n+1);
    reverse(b+1,b+n+1);
    long long sum=0;
    for (int i=1;i<=k*m;i++)
        sum+=b[i].first,vis[b[i].second]=1;
    vector<int> ret;
    int num=0;
    for (int i=1;i<=n;i++)
    {
        if (vis[i])num++;
        if (num>m)ret.push_back(i-1),num=1;
    }
    cout<<sum<<endl;
    for (auto x:ret)
        cout<<x<<' ';

}