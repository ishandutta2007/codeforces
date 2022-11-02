#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    vector < vector < int > > g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }

    vector < int > c;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < g[i].size(); ++j) {
            c.push_back(a[i]);
        }
    }
    sort(c.begin(), c.end());

    long long res = s;
    for (int i = 1; i < n; ++i) {
        printf("%lld ", res);
        if (!c.empty()) {
            res += c.back();
            c.pop_back();
        }
    }
    printf("\n");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        solve();
    }


    return 0;
}