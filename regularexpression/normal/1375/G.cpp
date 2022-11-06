#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n;
vector<int> g[N];
int white, black;

void dfs(int v, int dep = 0, int pr = -1) {
    if (dep & 1)
        white++;
    else
        black++;
    for (auto u : g[v]) {
        if (u != pr)
            dfs(u, dep + 1, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    cout << min(white, black) - 1;
    return 0;
}