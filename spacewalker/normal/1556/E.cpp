#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll INF = 1000000000000000000;

struct RangeSummary {
    ll minpf, maxpf, rsum; // the empty seq is included in these maximums
    ll minsf, maxsf;
    RangeSummary() : minpf(INF), maxpf(-INF), rsum(0), minsf(INF), maxsf(-INF) {}
    RangeSummary(int v) : minpf(min(0, v)), maxpf(max(0, v)), rsum(v),
        minsf(min(0, v)), maxsf(max(0, v)) {}
    RangeSummary operator || (RangeSummary ot) {
        RangeSummary ans;
        ans.rsum = rsum + ot.rsum;
        ans.minpf = min(minpf, rsum + ot.minpf);
        ans.maxpf = max(maxpf, rsum + ot.maxpf);
        ans.minsf = min(ot.minsf, ot.rsum + minsf);
        ans.maxsf = max(ot.maxsf, ot.rsum + maxsf);
        return ans;
    }
};

struct PSumTree {
    int al, ar;
    RangeSummary rs;
    PSumTree *left, *right;
    PSumTree() {}
    void combine() {
        rs = left->rs || right->rs;
    }
    PSumTree(int i, int j, vector<ll> &arr) : al(i), ar(j), rs(), left(nullptr), right(nullptr) {
        if (i == j) {
            rs = RangeSummary(arr[i]);
        } else {
            int k = (i + j) / 2;
            left = new PSumTree(i, k, arr);
            right = new PSumTree(k + 1, j, arr);
            combine();
        }
    }
    RangeSummary getrs(int i, int j) {
        if (ar < i || j < al) return RangeSummary();
        else if (i <= al && ar <= j) return rs;
        else return left->getrs(i, j) || right->getrs(i, j);
    }
};

int main() {
    int n, q; scanf("%d %d", &n, &q);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    vector<ll> bma(n);
    for (int i = 0; i < n; ++i) bma[i] = b[i] - a[i];
    PSumTree pst(0, n-1, bma);
    for (int qta = 0; qta < q; ++qta) {
        int l, r; scanf("%d %d", &l, &r);
        --l; --r;
        RangeSummary rs = pst.getrs(l, r);
        if (rs.rsum == 0 && rs.minpf >= 0) {
            printf("%lld\n", rs.maxpf);
        } else {
            printf("-1\n");
        }
    }
}