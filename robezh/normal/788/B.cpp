#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;

int n,m;
vector<int> G[N];
bool vis[N];
bool self_loop[N];
int self_cnt = 0;
int cnt = 0;

void dfs(int v) {
    vis[v] = true;
    for(int nxt : G[v]) if(!vis[nxt]) dfs(nxt);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    if(m <= 1) return cout << "0" << endl, 0;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        if(a == b) {
            self_cnt ++;
            self_loop[a] = true;
        }
        else {
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    for(int i = 0; i < n; i++) {
        if(!G[i].empty() || self_loop[i]) {
            dfs(i);
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i] && (!G[i].empty() || self_loop[i])) return cout << 0 << endl, 0;
    }
    ll res = 0;
    for(int i = 0; i < n; i++) {
        res += 1LL * G[i].size() * (G[i].size() - 1) / 2;
    }
    res += 1LL * self_cnt * (m - self_cnt) + 1LL * self_cnt * (self_cnt - 1) / 2;
    cout << res << endl;

}