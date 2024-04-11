#include <bits/stdc++.h>

using namespace std;
using ll = long long;

auto comp_preprocess(vector<ll> &p) {
    sort(begin(p), end(p));
    p.erase(unique(begin(p), end(p)), end(p));
    return [&] (ll v) {
        return distance(begin(p), lower_bound(begin(p), end(p), v));
    };
}

struct MilanTree {
    int al, ar;
    MilanTree *left, *right;
    int rmax;
    MilanTree() {}
    MilanTree(int i, int j) : al(i), ar(j), left(nullptr), right(nullptr), rmax(-1) {
        if (i != j) {
            int k = (i + j) / 2;
            left = new MilanTree(i, k);
            right = new MilanTree(k + 1, j);
        }
    }
    ~MilanTree() {
        if (left != nullptr) {
            delete left;
            delete right;
        }
    }
    void set(int i, int v) {
        // printf("MT %d %d: set %d %d\n", al, ar, i, v);
        if (i < al || ar < i) return;
        else if (al == ar) rmax = v;
        else {
            left->set(i, v); right->set(i, v);
            rmax = max(left->rmax, right->rmax);
            // printf("MT: %d %d %d [%d %d]\n", al, ar, rmax, left->rmax, right->rmax);
        }
    }
    int rangeMax(int i, int j) {
        if (j < al || ar < i) return -1;
        else if (i <= al && ar <= j) return rmax;
        else return max(left->rangeMax(i, j), right->rangeMax(i, j));
    }
};

int main() {
    int n; ll v; scanf("%d %lld", &n, &v);
    
    // reduce problem
    vector<ll> kicktimes(n);
    for (ll &v : kicktimes) scanf("%lld", &v);
    for (ll &t : kicktimes) t *= v;
    vector<ll> pos(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &pos[i]);
    vector<pair<ll, ll>> pts;
    for (int i = 0; i < n; ++i) pts.emplace_back(kicktimes[i] + pos[i], kicktimes[i] - pos[i]);
    // extra point; this is where we start
    pts.emplace_back(0, 0);
    n++;
    // coord compress
    sort(begin(pts), end(pts));
    vector<ll> xcs, ycs;
    for (auto [x, y] : pts) {
        xcs.emplace_back(x);
        ycs.emplace_back(y);
    }
    auto xcomp = comp_preprocess(xcs), ycomp = comp_preprocess(ycs);
    for (auto &[x, y] : pts) {
        x = xcomp(x);
        y = ycomp(y);
    }

    // solve actual problem
    MilanTree mt(0, n-1);
    for (int i = 0; i < n; ++i) mt.set(i, -1);
    for (auto [x, y] : pts) {
        int best = mt.rangeMax(0, y);
        if (x == xcomp(0) && y == ycomp(0)) { // if this is compressed origin
            best = 0;
        }
        // printf("%lld %lld (comp %lld %lld) best %d\n", xcs[x], ycs[y], x, y, best);
        if (best == -1) continue;
        mt.set(y, best + 1);
    }
    // -1 to remove the start point
    printf("%d\n", mt.rangeMax(0, n-1) - 1);
}