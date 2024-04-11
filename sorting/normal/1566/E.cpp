#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;

int n;
vector<int> adj[N], adj2[N];
int leafs, stubs, stub_leafs;

pair<int, int> dfs(int u, int p = -1){
    int cnt = 0, cnt_leafs = 0;
    vector<int> v;
    for(int to: adj[u]){
        if(to == p) continue;
        auto [x, add] = dfs(to, u);
        if(x == 1){
            ++cnt;
            ++cnt_leafs;
        }
        else if(!x){
            ++cnt;
        }
        else if(x == 2)
            v.push_back(add);
    }
    if(u == 1){
        for(int x: v)
            adj2[u].push_back(x);
        return {0, -1};
    }
    if(!cnt){
        ++leafs;
        for(int x: v)
            adj2[p].push_back(x);
        return {1, -1};
    }
    if(cnt == cnt_leafs){
        for(int x: v)
            adj2[u].push_back(x);
        ++stubs;
        stub_leafs += cnt_leafs;
        return {2, u};
    }
    return {0, -1};
}

int get_depth(int u, int p = -1){
    int mn = INT_MAX;
    for(int to: adj2[u]){
        if(to == p) continue;
        check_min(mn, get_depth(to, u));
    }
    if(mn == INT_MAX) mn = 0;
    mn += 1;
    return mn;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        adj[i].clear();
        adj2[i].clear();
    }

    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    leafs = stubs = stub_leafs = 0;
    dfs(1);

    if(leafs != stub_leafs){
        cout << leafs - stubs << "\n";
    }
    else{
        int d = get_depth(1);
        cout << leafs - stubs + 1 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve();
}
/*
1
11
1 2
2 3
2 4
4 5
1 6
6 7
6 8
8 9
7 10
10 11 
*/