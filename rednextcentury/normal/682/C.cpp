#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ret=0;
vector<pair<int,int> > adj[1000000];
ll a[1000000];
void dfs(int v,int pa=-1, ll mn = 0, ll l = 0){
    if (l - mn > a[v])return;
    ret++;
    for (auto u:adj[v]){
        if (u.first!=pa){
            dfs(u.first, v, min(mn, l+u.second), l + u.second);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=2;i<=n;i++){
        int p,w;
        cin>>p>>w;
        adj[p].push_back({i,w});
    }
    dfs(1);
    cout<<n-ret<<endl;
}