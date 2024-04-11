#include <bits/stdc++.h>
using namespace std;

struct StronglyConnectedComponents{
    vector<vector<int>> G,rG,C,T;
    vector<int> vs,cmp,used;
    StronglyConnectedComponents(int n):G(n),rG(n),cmp(n),used(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int v){
        used[v]=1;
        for (int u:G[v]) if(!used[u]) dfs(u);
        vs.emplace_back(v);
    }
    void rdfs(int v,int k){
        used[v]=1;
        cmp[v]=k;
        C[k].emplace_back(v);
        for (int u:rG[v]) if (!used[u]) rdfs(u,k);
    }
    int build(){
        int n=G.size();
        for (int i=0;i<n;++i) if (!used[i]) dfs(i);
        fill(used.begin(),used.end(),0);
        int k=0;
        for (int i=n-1;i>=0;--i){
            if (!used[vs[i]]){
                C.emplace_back(),T.emplace_back();
                rdfs(vs[i],k++);
            }
        }
        for (int v=0;v<n;++v) for (int u:G[v]){
            if (cmp[v]!=cmp[u]) T[cmp[v]].emplace_back(cmp[u]);
        }
        for (int i=0;i<k;++i){
            sort(T[i].begin(),T[i].end());
            T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
        }
        return k;
    }
    int operator[](int i) const{
        return cmp[i];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    vector<int> p(n),q(n);
    for (int i=0;i<n;++i) cin >> p[i],--p[i];
    for (int i=0;i<n;++i) cin >> q[i],--q[i];
    StronglyConnectedComponents SCC(n);
    for (int i=0;i<n-1;++i){
        SCC.add_edge(p[i],p[i+1]);
        SCC.add_edge(q[i],q[i+1]);
    }
    int m=SCC.build();
    if (m<k){cout << "NO" << '\n'; return 0;}
    cout << "YES" << '\n';
    for (int i=0;i<n;++i) cout << (char)('a'+min(k-1,SCC.cmp[i]));
    cout << '\n';
}