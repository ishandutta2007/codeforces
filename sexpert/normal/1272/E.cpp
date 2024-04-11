#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int dis[MAXN], arr[MAXN], ans[MAXN];
vector<int> adj[MAXN];

void bfs() {
    fill(dis, dis + MAXN, -1);
    dis[0] = 0;
    queue<int> q({0});
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        if(i - arr[i] >= 1)
            adj[i - arr[i]].push_back(i);
        if(i + arr[i] <= n)
            adj[i + arr[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        if(arr[i] % 2)
            adj[0].push_back(i);
    bfs();
    for(int i = 1; i <= n; i++) {
        if(arr[i] % 2 == 0)
            ans[i] = (dis[i] == -1 ? -1 : dis[i] - 1);
    }
    adj[0].clear();
    for(int i = 1; i <= n; i++)
        if(arr[i] % 2 == 0)
            adj[0].push_back(i);
    bfs();
    for(int i = 1; i <= n; i++) {
        if(arr[i] % 2)
            ans[i] = (dis[i] == -1 ? -1 : dis[i] - 1);
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}