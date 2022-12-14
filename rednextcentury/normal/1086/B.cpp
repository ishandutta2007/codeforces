#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    long double s;
    cin>>n>>s;
    s=s*2;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int num=0;
    for (int i=1;i<=n;i++)
    {
        if (adj[i].size()==1)num++;
    }
    cout<<setprecision(10)<<fixed<<s/num<<endl;

}