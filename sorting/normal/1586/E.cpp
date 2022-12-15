#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 3;

vector<int> b_adj[N], adj[N];
int n, m, q;
array<int, 2> quer[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(int to: b_adj[u]){
        if(vis[to]) continue;
        adj[u].push_back(to);
        adj[to].push_back(u);
        dfs(to);
    }
}

bool dfs2(int u, int end, vector<int> &path, int p = -1){
    path.push_back(u);
    if(u == end) return true;
    for(int to: adj[u]){
        if(to == p) continue;
        if(dfs2(to, end, path, u)) return true;
    }
    path.pop_back();
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        b_adj[x].push_back(y);
        b_adj[y].push_back(x);
    }

    dfs(1);

    cin >> q;
    for(int i = 0; i < q; ++i)
        cin >> quer[i][0] >> quer[i][1];

    vector<int> values;
    for(int i = 0; i < q; ++i){
        values.push_back(quer[i][0]);
        values.push_back(quer[i][1]);
    }
    sort(all(values));
    //values.resize(unique(all(values)) - values.begin());

    int start = 0, cnt_odd = 0;
    for(int i = 1; i < values.size(); ++i){
        if(values[i] != values[start]){
            if((i - start) & 1) ++cnt_odd;
            start = i;
        }
    }
    if(((int)values.size() - start) & 1) ++cnt_odd;

    if(cnt_odd){
        cout << "NO\n";
        cout << cnt_odd / 2 << "\n";
        return 0;
    }

    cout << "YES\n";
    for(int i = 0; i < q; ++i){
        vector<int> path;
        dfs2(quer[i][0], quer[i][1], path);
        cout << path.size() << "\n";
        for(int x: path)
            cout << x << " ";
        cout << "\n";
    }
}