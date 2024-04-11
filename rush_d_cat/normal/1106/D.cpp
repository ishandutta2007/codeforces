#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 100000 + 10;
set<int> st;
vector<int> g[N], ans;
int n,m,vis[N];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    st.insert(1);
    while(st.size()) {
        int u = *st.begin();
        if(vis[u]) {
            st.erase(u); continue;
        }
        ans.push_back(u); vis[u]=1;
        for(auto v:g[u]){
            if(vis[v]==0) st.insert(v);
        }
        st.erase(u);
    }
    for(auto x: ans) printf("%d ", x);
}