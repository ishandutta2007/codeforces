#include <bits/stdc++.h>
using namespace std;

int n, a[200000], ret[200000];
vector<int> adj[200000];

void bfs(int p) {
    vector<bool> visited(n);
    queue<pair<int, int>> q;
    for (int i=0; i<n; i++)
        if (a[i] % 2 == p)
            q.push(make_pair(i, 0));

    while (!q.empty()) {
        int u = q.front().first, d = q.front().second;
        q.pop();
        if (visited[u])
            continue;
        if (a[u] % 2 != p)
            ret[u] = d;
        visited[u] = true;
        for (int v : adj[u])
            q.push(make_pair(v, d + 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    for (int i=0; i<n; i++) {
        int l = i - a[i], r = i + a[i];
        if (l >= 0)
            adj[l].push_back(i);
        if (r < n)
            adj[r].push_back(i);
    }

    memset(ret, -1, sizeof(ret));
    bfs(0);
    bfs(1);

    for (int i=0; i<n; i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}