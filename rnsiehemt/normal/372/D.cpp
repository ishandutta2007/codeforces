#include <bits/stdc++.h>

const int maxn = 100*1000+5, maxd = 20;

int n, k, pos[maxn], idx[maxn], idxs, ans, sz, par[maxd][maxn], depth[maxn];
std::vector<int> e[maxn];

void go(int i, int p) {
    pos[idxs] = i;
    idx[i] = idxs++;
    for (int j : e[i]) if (j != p) {
        depth[j] = depth[i] + 1;
        par[0][j] = i;
        go(j, i);
    }
}

int getlca(int a, int b) {
    if (depth[a] > depth[b]) std::swap(a, b);
    for (int i = 0; i < maxd; i++) if ((depth[b] - depth[a]) & (1<<i)) {
        b = par[i][b];
    }
    if (a == b) return a;
    for (int i = maxd-1; i >= 0; i--) if (par[i][a] != par[i][b]) {
        a = par[i][a];
        b = par[i][b];
    }
    assert(par[0][a] == par[0][b]);
    return par[0][a];
}

std::set<int> s;

int dist(int a, int b) {
    return depth[a] + depth[b] - 2*depth[getlca(a, b)];
}

void add(int i) {
    auto me = s.insert(idx[i]).first;
    int l = pos[(me == s.begin() ? *s.rbegin() : *std::prev(me))];
    int r = pos[(std::next(me) == s.end() ? *s.begin() : *std::next(me))];
    sz += (dist(l, i) + dist(i, r) - dist(l, r))/2;
}

void rem(int i) {
    auto me = s.find(idx[i]);
    int l = pos[(me == s.begin() ? *s.rbegin() : *std::prev(me))];
    int r = pos[(std::next(me) == s.end() ? *s.begin() : *std::next(me))];
    sz -= (dist(l, i) + dist(i, r) - dist(l, r))/2;
    s.erase(idx[i]);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n-1; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        e[a].push_back(b); e[b].push_back(a);
    }
    par[0][0] = 0;
    go(0, -1);
    for (int d = 0; d+1 < maxd; d++) {
        for (int i = 0; i < n; i++) {
            par[d+1][i] = par[d][par[d][i]];
        }
    }
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (sz <= k-1) {
            if (r-l > ans) {
                ans = r-l;
            }
            if (r == n) {
                break;
            }
            add(r);
            r++;
        }
        rem(l);
    }
    printf("%d\n", ans);
}