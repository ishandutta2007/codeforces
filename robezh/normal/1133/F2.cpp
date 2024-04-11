#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;
typedef pair<int, int> P;

int n,m,D;
vector<int> G[N];
int f[N];
int a[N], b[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    f[x] = y;
}
bool same(int x, int y) {return find(x) == find(y);}

int cmp;
vector<P> res;
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> D;
    for(int i = 0; i < n; i++) f[i] = i;
    cmp = n;
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        if(a[i] != 0 && b[i] != 0 && !same(a[i], b[i])) {
            unite(a[i], b[i]);
            cmp--;
        }
    }
    set<int> S;
    for(int i = 0; i < m; i++) {
        if(a[i] == 0 || b[i] == 0) S.insert(find(a[i] + b[i]));
    }
    if(S.size() != cmp - 1 || cmp - 1 > D || G[0].size() < D) return cout << "NO" << endl, 0;
    vis[0] = true;
    queue<int> que;
    for(int nxt : G[0]) {
        if(S.find(find(nxt)) != S.end()) {
            S.erase(find(nxt));
            que.push(nxt);
            vis[nxt] = true;
            res.push_back({0, nxt});
            D--;
        }
    }
    for(int nxt : G[0]) {
        if(!vis[nxt] && D > 0) {
            vis[nxt] = true;
            que.push(nxt);
            res.push_back({0, nxt});
            D--;
        }
    }
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nxt : G[v]) {
            if(vis[nxt]) continue;
            vis[nxt] = true;
            res.push_back({v, nxt});
            que.push(nxt);
        }
    }
    cout << "YES" << endl;
    for(const auto &p : res) cout << p.first + 1 << " " << p.second + 1 << "\n";



}