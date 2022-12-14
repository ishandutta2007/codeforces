#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> at_depth[10000];
bool bad[10000];
int par[10000];
pair<int,int> query(vector<int> nodes){
    assert(nodes.size()>0);
    cout<<"? "<<nodes.size();
    for (auto x:nodes)cout<<' '<<x;
    cout<<endl;
    int a,dist;
    cin>>a>>dist;
    if (a<0)assert(0);
    return {a,dist};
}
vector<int> adj[100000];
bool vis[1000000];
int max_depth = 0;
void dfs(int v,int d=0){
    at_depth[d].push_back(v);
    max_depth = max(max_depth, d);
    vis[v]=1;
    bad[v]=0;
    for (auto u:adj[v]){
        if (!vis[u]) par[u]=v,dfs(u, d+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> all;
        for (int i=0;i<n;i++) {
            at_depth[i].clear();
            all.push_back(i+1);
            vis[i+1]=0;
            adj[i+1].clear();
        }
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int root,len;
        tie(root,len) = query(all);
        int path_len=len;
        max_depth=0;
        dfs(root);
        int l=1,r=max_depth;
        int ans=0;
        int node1=-1,node2=-1;
        while(l<=r){
            int mid = (l+r)/2;
            vector<int> nodes;
            for (int i=mid;i<=max_depth;i++){
                for (auto x:at_depth[i]) nodes.push_back(x);
            }
            tie(root, len) = query(nodes);
            if (len == path_len) ans = mid, l=mid+1, node1=root;
            else r=mid-1;
        }
        int other_depth = path_len - ans;
        vector<int> nodes;
        int v=node1;
        while(ans--){
            bad[v]=1;
            v = par[v];
        }
        for (auto x:at_depth[other_depth]){
            if (!bad[x]) nodes.push_back(x);
        }
        tie(node2, len) = query(nodes);
        cout<<"! "<<node1<<' '<<node2<<endl;
        string ret;
        cin>>ret;
        if (ret!="Correct")assert(0);
    }
}