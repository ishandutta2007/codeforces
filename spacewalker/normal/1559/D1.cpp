#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1000000000;

struct ufds {
    vector<int> p;
    int n;
    ufds(int n) : p(n, -1), n(n) {}
    int find(int i) {
        return p[i] < 0 ? i : p[i] = find(p[i]);
    }
    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return false;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j]; p[j] = i;
        return true;
    }
};

vector<int> makeCompArray(vector<int> v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    return v;
}

int useCompArray(int v, vector<int> &comp) {
    return distance(begin(comp), lower_bound(begin(comp), end(comp), v));
}

int main() {
    int n, m1, m2; scanf("%d %d %d", &n, &m1, &m2);
    ufds mocha(n), diana(n);
    for (int i = 0; i < m1; ++i) {
        int u, v; scanf("%d %d", &u, &v); --u; --v;
        mocha.join(u, v);
    }
    for (int i = 0; i < m2; ++i) {
        int u, v; scanf("%d %d", &u, &v); --u; --v;
        diana.join(u, v);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (mocha.find(i) == mocha.find(j) || diana.find(i) == diana.find(j)) continue;
            ans.emplace_back(i, j);
            mocha.join(i, j);
            diana.join(i, j);
        }
    }
    printf("%lu\n", ans.size());
    for (auto [a, b] : ans) printf("%d %d\n", a + 1, b + 1);
}