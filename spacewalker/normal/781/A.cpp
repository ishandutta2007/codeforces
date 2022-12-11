#include <bits/stdc++.h>

using namespace std;

void assign(int v, int p, vector<vector<int>> &tree, vector<int> &ans) {
    int cc = 0;
    for (int nxt : tree[v]) {
        if (nxt == p) continue;
        while ((p != -1 && ans[p] == cc) || (ans[v] == cc)) ++cc;
        ans[nxt] = cc++;
        assign(nxt, v, tree, ans);
    }
}

int main() {
    int n; scanf("%d", &n);
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> ans(n, -1);
    ans[0] = 0;
    assign(0, -1, tree, ans);
    printf("%d\n", *max_element(begin(ans), end(ans)) + 1);
    for (int v : ans) printf("%d ", v + 1);
    printf("\n");
    return 0;
}