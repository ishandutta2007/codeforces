#include <bits/stdc++.h>

using namespace std;
using segment = vector<int>;
using crange = tuple<int, segment, int, segment, int>;
constexpr int RMAX = 10;

struct TooUnionTooFind {
    vector<int> p;
    TooUnionTooFind(int n) : p(n, -1) {}
    void reset() {p.assign(p.size(), -1);}
    int find(int i) {
        return (p[i] < 0 ? i : p[i] = find(p[i]));
    }
    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return false;
        else if (p[i] > p[j]) swap(i, j);
        p[i] += p[j]; p[j] = i;
        return true;
    }
};


vector<int> nums[RMAX];

int n, m;
vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

crange merge(const crange &a, const crange &b) {
    const auto &[ali, aleft, act, aright, ari] = a;
    const auto &[bli, bleft, bct, bright, bri] = b;
    if (act == 0) return b;
    if (bct == 0) return a;
    static TooUnionTooFind uf(4 * RMAX);
    uf.reset();
    int newct = act + bct;
    for (int i = 0; i < n; ++i) {
        if (nums[i][ari] == nums[i][bli] && uf.join(aright[i], bleft[i] + 2 * RMAX)) --newct;
    }
    vector<int> newLeft = aleft, newRight = bright;
    for (int &v : newLeft) v = uf.find(v);
    for (int &v : newRight) v = uf.find(v + 2 * RMAX);
    vector<int> compidx(4 * RMAX, -1);
    for (int v : newLeft) compidx[v] = 0;
    for (int v : newRight) compidx[v] = 0;
    int ccompt = 0;
    for (int &v : compidx) if (v == 0) v = ccompt++;
    for (int &v : newLeft) v = compidx[v];
    for (int &v : newRight) v = compidx[v];
    return {ali, newLeft, newct, newRight, bri};
}

struct hidion {
    int ai, aj;
    hidion *left, *right;
    crange cr;
    hidion() {}
    hidion(int i, int j) : ai(i), aj(j), left(nullptr), right(nullptr) {
        if (i == j) {
            segment stComps(n, 0);
            for (int k = 1; k < n; ++k) stComps[k] = stComps[k-1] + (nums[k][i] != nums[k-1][i] ? 1 : 0);
            cr = {i, stComps, stComps.back() - stComps.front() + 1, stComps, i};
        } else {
            int k = (i + j) / 2;
            left = new hidion(i, k);
            right = new hidion(k + 1, j);
            cr = merge(left->cr, right->cr);
        }
    }
    crange rangeMerge(int i, int j) {
        if (aj < i || j < ai) return {-1, segment(), 0, segment(), -1};
        else if (i <= ai && aj <= j) return cr;
        else return merge(left->rangeMerge(i, j), right->rangeMerge(i, j));
    }
};

int main() {
    int q; scanf("%d %d %d", &n, &m, &q); 
    for (int i = 0; i < n; ++i) {
        nums[i].assign(m, 0);
        for (int j = 0; j < m; ++j) scanf("%d", &nums[i][j]);
    }
    hidion orz(0, m-1);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r); --l; --r;
        printf("%d\n", get<2>(orz.rangeMerge(l, r)));
    }
}