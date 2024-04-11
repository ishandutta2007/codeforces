#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n, m;
set<int> st, g[N];
void dfs(int u) {
    vector<int> d; 
    for(auto x: st) {
        if (g[u].count(x)) continue;
        d.push_back(x);
    }
    for(auto x: d) {
        st.erase(x);
    }
    for(auto x: d) {
        dfs(x);
    }
    d.clear();
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d",&u,&v);
        g[u].insert(v), g[v].insert(u);
    }
    for(int i=1;i<=n;i++) st.insert(i);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if (st.count(i)) {
            st.erase(i);
            dfs(i); ans ++;
        }
    }
    printf("%d\n", ans - 1);
}