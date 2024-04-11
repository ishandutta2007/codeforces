#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct edge{
    int r, u, v;
    bool operator<(const struct edge &y) const{
        return r < y.r;
    }
};

int N, r[6005];
map<pair<int, int>, int> dp;
vector<int> adj[6005];
struct edge all[12005];

void write(int i, int r, int u, int v){
    all[i].r = r;
    all[i].u = u;
    all[i].v = v;
}

int dfs(int loc, int par, int lim){
    int ans = r[loc] < lim;
    if(r[par] < lim) ans = max(ans, dp[make_pair(loc, par)]);
    
    for(int i=0; i<adj[loc].size(); i++)
        if(adj[loc][i] == par) continue;
        else ans = max(ans, dfs(adj[loc][i], loc, lim));
    return ans;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> r[i];
    for(int i=0; i+1<N; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        write(2*i, r[b], a, b);
        write(2*i+1, r[a], b, a);
    }

    sort(all, all+(2*N-2));

    int ans = 0;
    for(int i=0; i<2*N-2; i++){
        pair<int, int> key = make_pair(all[i].u, all[i].v);
        dp[key] = 1 + dfs(key.first, key.second, all[i].r);
        ans = max(ans, dp[key]);
    }    
    cout << ans << endl;
    return 0;
}