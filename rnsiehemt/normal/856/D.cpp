#include <bits/stdc++.h>

const int maxn = 200*1000+5;

struct BIT {
    long long v[maxn];
    void backendup(int i, long long a) {
        i++;
        while (i < maxn) {
            v[i] += a;
            i += (i&-i);
        }
    }
    long long qu(int i) {
        i++;
        long long sum = 0;
        while (i > 0) {
            sum += v[i];
            i -= (i&-i);
        }
        return sum;
    }
    void up(int l, int r, long long a) {
        backendup(l, a);
        backendup(r, -a);
    }
} me_rt, allch_rt;

int n, m, p[maxn], sz[maxn], label[maxn], nextLabel, jump[20][maxn], depth[maxn];
long long me[maxn], allch[maxn];
std::vector<int> c[maxn];
std::vector<std::tuple<int,int,int>> choices[maxn];

void dfs(int i) {
    label[i] = nextLabel++;
    sz[i] = 1;
    jump[0][i] = p[i];
    for (int j : c[i]) {
        depth[j] = depth[i] + 1;
        dfs(j);
        sz[i] += sz[j];
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) std::swap(a, b);
    for (int d = 19; d >= 0; d--) if (depth[b] - (1<<d) >= depth[a]) {
        b = jump[d][b];
    }
    if (b == a) return a;
    for (int d = 19; d >= 0; d--) if (jump[d][a] != jump[d][b]) {
        a = jump[d][a];
        b = jump[d][b];
    }
    assert(p[a] == p[b]);
    assert(a != b);
    return p[a];
}

void go(int i) {
    for (int j : c[i]) {
        go(j);
        allch[i] += me[j];
    }

    me[i] = allch[i];

    for (auto &choice : choices[i]) {
        int u, v, c;
        std::tie(u, v, c) = choice;
        //printf("choice %d %d %d at %d\n", u, v, c, i);

        long long cur = allch_rt.qu(label[u]) + allch_rt.qu(label[v]) + allch[i] - me_rt.qu(label[u]) - me_rt.qu(label[v]) + c;
        if (cur > me[i]) me[i] = cur;
    }

    me_rt.up(label[i], label[i] + sz[i], me[i]);
    allch_rt.up(label[i], label[i] + sz[i], allch[i]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d", p+i);
        p[i]--;
        c[p[i]].push_back(i);
    }

    dfs(0);
    for (int d = 0; d+1 < 20; d++) for (int i = 0; i < n; i++) {
        jump[d+1][i] = jump[d][jump[d][i]];
    }

    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--; v--;
        choices[lca(u, v)].emplace_back(u, v, c);
    }

    go(0);

    printf("%lld\n", me[0]);
}