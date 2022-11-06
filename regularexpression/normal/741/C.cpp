#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()

int n, a[100000], b[100000];
vector<int> g[200000];
int col[200000];

void add(int v, int u) {
    g[v].pb(u);
    g[u].pb(v);
}

void dfs(int v) {
    for (auto u : g[v]) {
        if (col[u] == -1) {
            col[u] = col[v] ^ 1;
            dfs(u);
        } else if (col[v] == col[u]) {
            cout << "-1\n";
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        add(a[i], b[i]);
    }
    for (int i = 0; i < n * 2; i += 2) add(i, i + 1);
    memset(col, 255, sizeof(col));
    for (int i = 0; i < n * 2; i++) {
        if (col[i] == -1) {
            col[i] = 0;
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) cout << col[a[i]] + 1 << " " << col[b[i]] + 1 << '\n';
    return 0;
}