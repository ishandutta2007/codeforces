#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1000000 + 10;
int n, k;
vector<int> g[N];

int ans = 0;
int dfs(int u,int p) {
    if (g[u].size() == 1) {
        return 0;
    }
    vector<int> vec;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i]; if(p==v) continue;
        vec.push_back(dfs(v, u)+1);
    }
    sort(vec.begin(), vec.end());
    while(vec.size() >= 2) {
        if (vec[vec.size()-1] + vec[vec.size()-2] <= k) break;
        ans ++; vec.pop_back();
    }
    return vec[(int)vec.size()-1];
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++) {
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v), g[v].push_back(u);
    }
    int rt = -1;
    for(int i=1;i<=n;i++) {
        if (g[i].size()>=2) rt = i;
    }
    dfs(rt, rt);
    cout << ans+1 << endl;
}