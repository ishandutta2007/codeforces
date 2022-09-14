#include <bits/stdc++.h>

using namespace std;
int n,u,v,k,d,x=0;

int main(){
    cin>>n>>k>>d;
    vector<int>d(n+1,1000000),used(n+1,0);//,need(n,0);
    queue<int>q;
    for(int i=0;i<k;i++){
        cin>>v;
        d[v]=0;
        q.push(v);
    }
    vector<vector<pair<int,int> > >g(n+1);
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(make_pair(v,i));
        g[v].push_back(make_pair(u,i));
    }
    vector<bool>ans(n,1);
    while(!q.empty()){
        v=q.front();
        q.pop();
        if(used[v]) continue;
        used[v]=1;
        for(int i=0;i<g[v].size();i++){
            if(d[g[v][i].first]>d[v]+1){
                d[g[v][i].first]=d[v]+1;
                q.push(g[v][i].first);
                ans[g[v][i].second]=0;
                x++;
            }
        }
    }
    cout<<n-1-x<<endl;
    for(int i=1;i<n;i++){
        if(ans[i])
            cout<<i<<' ';
    }
    return 0;
}