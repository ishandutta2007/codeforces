#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int maxN = 1100000;
int c[maxN];

vector < vector < pair < int, int > > > g;
int n;

map < int, int > M;

void handle(int add) {
    if (add == 0) {
        return;
    }

    g.push_back({});
    ++n;
    g[n - 1].push_back({ n - 2, add });
}

void output() {
    int m = 0;
    for (int i = 0; i < g.size(); ++i) {
        m += g[i].size();
    }

    cout << "YES" << endl;
    cout << n << " " << m << endl;
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            int u = i, v = g[i][j].first, w = g[i][j].second;
            u = n - u;
            v = n - v;
            cout << u << " " << v << " " << w << endl;
        }
    }
}

void dfs(int v, int len) {
    if (v == 0) {
        ++M[len];
    }
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i].first, len + g[v][i].second);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    n = 0;

    int l, r;
    cin >> l >> r;

    int add = (l - 1);
    r -= add;
    l -= add;

    int mx = -1;
    --r;

    for (int i = 0; i <= 20; ++i) {
        if (r & (1 << i)) {
            mx = i;
        }
    }
    g.push_back({});
    g.push_back({});
    n += 2;
    g[1].push_back({ 0, 1 });

    
    if (r == 0) {
        handle(add);
        output();
        return 0;
    }

    for (int i = 0; i < mx; ++i) {
        ++n;
        g.push_back({});
        g[n - 1].push_back({ 0, 1 });
        int start = 2, len = 1;
        for (int j = 1; j + 1 < n; ++j) {
            g[n - 1].push_back({ j, start - 1 });
            start += len;
            len += len;
        }
    }

    ++n;
    g.push_back({});
    g[n - 1].push_back({ 0, 1 });
    int start = 2;
    for (int i = 0; i <= mx; ++i) {
        if (r & (1 << i)) {
            g[n - 1].push_back({ i + 1, start - 1 });
            start += (1 << i);
        }
    }
    handle(add);
    output();

    /*dfs(n - 1, 0);
    for (auto it : M) {
        cout << it.first << " " << it.second << endl;
    }*/


    return 0;
}