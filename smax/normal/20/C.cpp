
// Problem : C. Dijkstra?
// Contest : Codeforces Alpha Round #20 (Codeforces format)
// URL : http://codeforces.com/problemset/problem/20/C
// Memory Limit : 64 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int pred[MAXN];
long long INF, dist[MAXN];
vector<pair<int, int>> adj[MAXN];

void dijkstra(int s) {
    memset(dist, 127, sizeof(dist));
    memset(pred, -1, sizeof(pred));
    INF = dist[0];
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (p.first > dist[p.second])
            continue;

        for (auto e : adj[p.second])
            if (p.first + e.second < dist[e.first]) {
                dist[e.first] = p.first + e.second;
                pred[e.first] = p.second;
                pq.push({dist[e.first], e.first});
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a-1].emplace_back(b-1, w);
        adj[b-1].emplace_back(a-1, w);
    }
    
    dijkstra(0);
    
    if (dist[n-1] == INF)
        cout << "-1\n";
    else {
        stack<int> ret;
        int u = n - 1;
        while (u != -1) {
            ret.push(u + 1);
            u = pred[u];
        }
        
        while (!ret.empty()) {
            cout << ret.top() << " ";
            ret.pop();
        }
        cout << "\n";
    }

    return 0;
}