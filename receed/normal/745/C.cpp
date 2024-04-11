#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>

using namespace std;
vector<vector<int> > g(1001);
vector<int>col(1001,0);

int dfs(int v){
    col[v]=1;
    int res=1;
    for(int i=0;i<g[v].size();i++){
        if (col[g[v][i]]==0){
            res+=dfs(g[v][i]);
        }
    }
    return res;
}

int main(){
    int n,m,k,a,b,sm,now;
    cin>>n>>m>>k;
    sm=n;
    vector<int> stol(k);
    for(int i=0;i<k;i++){
        cin>>stol[i];
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>comp;
    for(int i=0;i<k;i++){
        if (col[stol[i]]==0){
            now=dfs(stol[i]);
            comp.push_back(now);
            sm-=now;

        }
    }
    sort(comp.begin(),comp.end());
    comp[comp.size()-1]+=sm;
    int ans=-m;
    for(int i=0;i<comp.size();i++){
        ans+=comp[i]*(comp[i]-1)/2;
    }
    cout<<ans;
}