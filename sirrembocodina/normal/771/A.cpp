#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

vector<int> g[150100];
bool used[150100];
int cnt = 0, cur = 0;
bool ok = true;

void dfs(int v) {
    used[v] = true;
    ++cnt;
    if (g[v].size() != cur) {
        ok = false;
    }
    forn (i, g[v].size()) {
        int to = g[v][i];
        if (used[to]) {
            continue;
        }
        dfs(to);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    forn (i, n) {
        if (used[i]) {
            continue;
        }
        cnt = 0;
        cur = g[i].size();
        ok = true;
        dfs(i);
        if (cur != cnt - 1 || !ok) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}