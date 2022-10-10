#include <bits/stdc++.h>
using namespace std;

int p[200000], ret[200000];
bool visited[200000];

int dfs(int u, int d) {
    if (visited[u])
        return d;
    visited[u] = true;
    ret[u] = dfs(p[u] - 1, d + 1);
    return ret[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> p[i];

        memset(visited, false, sizeof(visited));
        for (int i=0; i<n; i++)
            if (!visited[i])
                dfs(i, 0);

        for (int i=0; i<n; i++)
            cout << ret[i] << " ";
        cout << "\n";
    }

    return 0;
}