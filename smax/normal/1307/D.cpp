#include <bits/stdc++.h>
using namespace std;

int a[200000], distS[200000], distE[200000];
vector<int> adj[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<k; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    memset(distS, -1, sizeof(distS));
    queue<int> q;
    q.push(0);
    distS[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (distS[v] == -1) {
                q.push(v);
                distS[v] = distS[u] + 1;
            }
    }

    memset(distE, -1, sizeof(distE));
    q.push(n-1);
    distE[n-1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (distE[v] == -1) {
                q.push(v);
                distE[v] = distE[u] + 1;
            }
    }

    sort(a, a + k, [&] (int x, int y) {
        return distS[x] - distE[x] < distS[y] - distE[y];
    });

    int ret = 0, mx = distS[a[0]];
    for (int i=1; i<k; i++) {
        ret = max(ret, mx + distE[a[i]] + 1);
        mx = max(mx, distS[a[i]]);
    }

    cout << min(ret, distS[n-1]) << "\n";

    return 0;
}