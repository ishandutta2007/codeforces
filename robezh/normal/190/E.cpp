#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50;

int n, m;
unordered_set<int> G[N], S;
int cnt = 0;
vector<int> res[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    for(int i = 0; i < n; i++) S.insert(i);
    queue<int> que;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        que.push(i);
        vis[i] = true;
        S.erase(i);
        res[cnt].push_back(i);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            auto it = S.begin();
            while(it != S.end()) {
                if(G[v].count(*it)) {
                    it++;
                    continue;
                }
                res[cnt].push_back(*it);
                vis[*it] = true;
                que.push(*it);
                it = S.erase(it);
            }
        }
        cnt++;
    }
    cout << cnt << "\n";
    for(int i = 0; i < cnt; i++) {
        cout << res[i].size();
        for(int x : res[i]) cout << " " << x + 1;
        cout << "\n";
    }

}