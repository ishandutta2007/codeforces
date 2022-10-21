#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50;

int n, m;
vector<int> G[N];
int c[N];
queue<int> que;
bool vis[N];

bool is_bad(int v) {
    int cnt = 0;
    for(int nxt : G[v]) cnt += (c[nxt] == c[v]);
    return cnt > 1;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) if(is_bad(i)) {
        que.push(i);
        vis[i] = true;
    }
    while(!que.empty()) {
        int v = que.front(); que.pop(); vis[v] = false;
        if(!is_bad(v)) continue;
        c[v] = !c[v];
        for(int nxt : G[v]) {
            if(!vis[nxt] && is_bad(nxt)) {
                que.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    for(int i = 0; i < n; i++) cout << c[i];
}