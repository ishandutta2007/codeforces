#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN], olst, lst;
int pos[MAXN], vist[MAXN];

bool cmp(int x, int y) {
    return pos[x] < pos[y];
}

void bfs(int s) {
    queue<int> q;
    vist[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        lst.push_back(u);
        for(auto v : adj[u]) {
            if(!vist[v]) {
                q.push(v);
                vist[v] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        olst.push_back(x);
        pos[x] = i;
    }
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), cmp);
    bfs(1);
    for(int i = 0; i < n; i++) {
        if(lst[i] != olst[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}