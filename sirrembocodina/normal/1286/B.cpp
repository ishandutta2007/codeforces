#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

int p[2010];
int c[2010];
int a[2010];
vector<int> sons[2010];

int dfs2(int v, int x, int left) {
    int res = left;
    for (auto to: sons[v]) {
        left -= dfs2(to, x, left);
    }
    if (a[v] > x || (a[v] == x && left > 0)) {
        if (a[v] == x) {
            left--;
        }
        a[v] += 2;
    }
    return res - left;
}

vector<int> dfs(int v) {
    vector<int> x;
    for (auto to: sons[v]) {
        vector<int> y = dfs(to);
        for (auto z: y) {
            x.pb(z);
        }
    }
    sort(x.begin(), x.end());
    if (c[v] > int(x.size())) {
        cout << "NO" << endl;
        exit(0);
    }
    int res;
    if (c[v] == int(x.size())) {
        if (x.empty()) {
            res = 1;
        } else {
            res = x.back() + 1;
        }
    } else {
        res = x[c[v]] + 1;
        int left = 0;
        for (int i = c[v]; i < int(x.size()); ++i) {
            if (x[i] == res - 1) {
                left++;
            }
            x[i] += 2;
        }
        dfs2(v, res - 1, left);
    }
    a[v] = res;
    x.pb(res);
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int root = 0;
    forn (i, n) {
        cin >> p[i] >> c[i];
        p[i]--;
        if (p[i] >= 0) {
            sons[p[i]].pb(i);
        } else {
            root = i;
        }
    }
    dfs(root);
    cout << "YES" << endl;
    forn (i, n) {
        cout << a[i] << " ";
    }
    cout << endl;
}