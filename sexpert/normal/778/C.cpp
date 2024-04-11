#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, char> edge;
typedef array<int, 26> node;

node def = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
const int MAXN = 3e5 + 10;
int sz[MAXN], ht[MAXN], ans[MAXN], n, save;
vector<int> byh[MAXN];
vector<node> tr[MAXN];
vector<edge> adj[MAXN];

void fuse(vector<node> &T1, vector<node> &T2, int cur1, int cur2) {
    for(int ch = 0; ch < 26; ch++) {
        if(T2[cur2][ch] == -1)
            continue;
        if(T1[cur1][ch] == -1) {
            T1[cur1][ch] = T1.size();
            T1.push_back(def);
        }
        fuse(T1, T2, T1[cur1][ch], T2[cur2][ch]);
    }
}

void walk(vector<node> &T1, vector<node> &T2, int cur1, int cur2) {
    save++;
    for(int ch = 0; ch < 26; ch++) {
        if(T1[cur1][ch] != -1 && T2[cur2][ch] != -1)
            walk(T1, T2, T1[cur1][ch], T2[cur2][ch]);
    }
}

void dfs_sz(int s, int h = 1) {
    sz[s] = 1;
    ht[s] = 1;
    byh[h].push_back(s);
    for(auto e : adj[s]) {
        dfs_sz(e.first, h + 1);
        sz[s] += sz[e.first];
    }
    sort(adj[s].begin(), adj[s].end(), [&](edge a, edge b){
        return sz[a.first] > sz[b.first];
    });
}

void dfs(int s) {
    ans[s] = 1;
    array<int, 26> pos = def;
    if(adj[s].size()) {
        for(auto e : adj[s])
            dfs(e.first);
        swap(tr[s], tr[adj[s][0].first]);
        ans[s] = 0;
        ans[s] += tr[s].size();

        vector<node> fused;
        fused.push_back(def);
        for(int i = 1; i < adj[s].size(); i++) {
            int v = adj[s][i].first;
            fuse(fused, tr[v], 0, (int)tr[v].size() - 1);
        }
        save = 0;
        ans[s] += fused.size();
        walk(tr[s], fused, (int)tr[s].size() - 1, 0);
        ans[s] -= save;
        pos[adj[s][0].second - 'a'] = (int)tr[s].size() - 1;
        int alef = tr[s].size();
        for(int i = 1; i < adj[s].size(); i++) {
            for(auto &x : tr[adj[s][i].first]) {
                for(auto &y : x) {
                    if(y != -1)
                        y += alef;
                }
            }
            copy(tr[adj[s][i].first].begin(), tr[adj[s][i].first].end(), back_inserter(tr[s]));
            tr[adj[s][i].first].clear();
            tr[adj[s][i].first].shrink_to_fit();
            pos[adj[s][i].second - 'a'] = (int)tr[s].size() - 1;
            alef = tr[s].size();
        }
    }
    tr[s].push_back(pos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    dfs_sz(1);
    dfs(1);
    //for(int i = 1; i <= n; i++)
    //    cout << ans[i] << '\n';
    int bst = -1, mn = INT_MAX, cur = 0;
    for(int h = 1;;h++) {
        if(byh[h].empty())
            break;
        int su = 0;
        for(auto x : byh[h])
            su += ans[x];
        if(su + cur < mn) {
            mn = su + cur;
            bst = h;
        }
        cur += byh[h].size();
    }
    cout << mn << '\n' << bst << '\n';
}