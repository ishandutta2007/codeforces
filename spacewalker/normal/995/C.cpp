#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct MoveSet {
    pair<int, int> cumu;
    vector<pair<int, int>> *steps;
    MoveSet() {}
    MoveSet(vector<pair<int, int>> *istep, pair<int, int> init) : steps(istep), cumu(init) {}
    MoveSet& operator += (MoveSet &o) {
        cumu.first += o.cumu.first;
        cumu.second += o.cumu.second;
        steps->insert(end(*steps), begin(*(o.steps)), end(*(o.steps)));
        return *this;
    }
    MoveSet operator + (MoveSet &o) {
        MoveSet a = *this; a += o;
        return a;
    }
    MoveSet& operator -= (MoveSet &o) {
        cumu.first -= o.cumu.first;
        cumu.second -= o.cumu.second;
        int stz = steps->size();
        steps->insert(end(*steps), begin(*(o.steps)), end(*(o.steps)));
        for (int i = stz; i < steps->size(); ++i) (*steps)[i].first *= -1;
        return *this;
    }
    MoveSet operator - (MoveSet &o) {
        MoveSet a = *this; a -= o;
        return a;
    }
    bool operator < (const MoveSet &o) const {
        if (steps->size() != o.steps->size()) return steps->size() > o.steps->size();
        else return steps < o.steps;
    }
    int bucketID() {
        ll cx = cumu.first, cy = cumu.second;
        int ans = 0;
        if (cx == 0 && cy == 0) return 0;
        if (cy < 0 || (cy == 0 && cx < 0)) {
            cx *= -1; cy *= -1;
            ans += 3;
        }
        // cot v = cx / cy
        if (cy > 0) { // else, ans = 0
            // cx/cy can be in (inf, rt3/3], (rt3/3, -rt3/3], or (-rt3/3, -inf)
            // cx/cy >= rt3/3 => 3cx >= rt3 cy
            if (cx > 0 && 3 * cx * cx >= cy) {
                ans += 0; 
            // cx/cy >= -rt3/3 => 3cx >= -rt3 cy
            } else if (cx < 0 && 3 * cx * cx <= cy) {
                ans += 2;
            } else {
                ans += 1;
            }
        }
        return ans;
    }
    ll sqnorm() {
        ll cx = cumu.first, cy = cumu.second;
        return cx*cx + cy*cy;
    }
};

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> v(n);
    vector<vector<pair<int, int>>*> isteps(n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &v[i].first, &v[i].second);
    vector<set<MoveSet>> buckets(6);
    for (int i = 0; i < n; ++i) {
        isteps[i] = new vector<pair<int, int>>{{1, i + 1}};
        MoveSet ms(isteps[i], v[i]);
        buckets[ms.bucketID()].insert(ms);
    }
    auto bucketToMergeIn = [&] () {
        for (int i = 0; i < 6; ++i) if (buckets[i].size() > 1) return i;
        return -1;
    };
    for (int btm = bucketToMergeIn(); btm != -1; btm = bucketToMergeIn()) {
        auto to_first = buckets[btm].begin(), to_second = next(buckets[btm].begin(), 1);
        MoveSet to = *to_first, from = *to_second;
        buckets[btm].erase(to); buckets[btm].erase(from);
        to -= from;
//        printf("combined vectors to make %d %d\n", to.cumu.first, to.cumu.second);
        buckets[to.bucketID()].insert(to);
    }
    vector<MoveSet> finalBuckets;
    for (int i = 0; i < 6; ++i) if (buckets[i].size() > 0) {
        assert(buckets[i].size() == 1);
        finalBuckets.push_back(*(buckets[i].begin()));
    }
    sort(begin(finalBuckets), end(finalBuckets));
    for (int msk = 0; msk < (1 << ((int)finalBuckets.size() - 1)); ++msk) {
        MoveSet ms = finalBuckets[0];
        for (int i = 0; i < (int)finalBuckets.size() - 1; ++i) {
            if (msk & (1 << i)) ms += finalBuckets[i + 1];
            else ms -= finalBuckets[i + 1];
        }
        if (ms.sqnorm() <= 2250000000000) {
            vector<int> ans(n, 1);
            for (auto [sign, idx] : *ms.steps) {
                ans[idx - 1] = sign; 
            }
            for (int v : ans) printf("%d ", v);
            printf("\n");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) delete isteps[i];
    assert(false);
}