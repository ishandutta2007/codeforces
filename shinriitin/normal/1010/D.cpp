#include <bits/stdc++.h>

const int max_N = (int) 1e6 + 21;

int n, val[max_N], leaf[max_N], tot, f[max_N];

std::vector<int> vec[max_N];

char tp[max_N][5], ans[max_N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int u, int v) {
    f[find(u)] = find(v);
}

void dfs(int u) {
    if (*tp[u] == 'I') return;
    for (auto v : vec[u]) dfs(v);
    if (*tp[u] == 'N') {
        val[u] = !val[vec[u][0]];
        merge(u, vec[u][0]);
    } else {
        int l = vec[u][0], r = vec[u][1];
        if (*tp[u] == 'A') {
            val[u] = val[l] & val[r];
            if (val[l]) merge(u, r);
            if (val[r]) merge(u, l);
        } else if (*tp[u] == 'O') {
            val[u] = val[l] | val[r];
            if (!val[l]) merge(u, r);
            if (!val[r]) merge(u, l);
        } else {
            val[u] = val[l] ^ val[r];
            merge(u, l), merge(u, r);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        scanf("%s", tp[i]);
        if (*tp[i] == 'I') {
            scanf("%d", val + i);
            leaf[++tot] = i;
        } else {
            int sz = (*tp[i] == 'N') ? 1 : 2, x;
            while (sz--) {
                scanf("%d", &x);
                vec[i].push_back(x);
            }
        }
    }
    dfs(1);
    for (int i = 1; i <= tot; ++i) {
        ans[i - 1] = '0' + (find(leaf[i]) == find(1) ? !val[1] : val[1]);
    }
    ans[tot] = '\0';
    puts(ans);
    return 0;
}