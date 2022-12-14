#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 300005;

int n, m, k;
vector <int> h[MaxN];

bool nie() {
    printf("impossible\n");
    exit(0);
}

void dfs(set <int> &vis, vector <int> &res, int v) {
    vector <int> isOk;
    for (set <int> :: iterator it = vis.begin(); it != vis.end(); ++it) {
        if (binary_search(h[v].begin(), h[v].end(), *it) || *it == v) {
            continue;
        }
        isOk.push_back(*it);
    }
    for (int i = 0; i < (int)isOk.size(); ++i) {
        vis.erase(isOk[i]);
    }
    res.push_back(v);
    for (int i = 0; i < (int)isOk.size(); ++i) {
        dfs(vis, res, isOk[i]);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        h[x].push_back(y);
        h[y].push_back(x);
    }
    set <int> vis;
    for (int i = 1; i <= n; ++i) {
        if ((int)h[i].size() + k * (i == 1) >= n - 1 + (i == 1)) {
            nie();
        }
        sort(h[i].begin(), h[i].end());
        vis.insert(i);
    }
    vis.erase(1);
    int mi = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis.count(i)) {
            vector <int> tmp;
            vis.erase(i);
            dfs(vis, tmp, i);
            tmp.push_back(i);
            bool isOk = false;
            for (int j = 0; j < (int)tmp.size() && !isOk; ++j) {
                isOk |= !binary_search(h[1].begin(), h[1].end(), tmp[j]);
            }
            if (!isOk) {
                nie();
            }
            ++mi;
        }
    }
    if (mi > k) {
        nie();
    }
    cout << "possible\n";
    return 0;
}