#include <bits/stdc++.h>

using namespace std;
constexpr int RBOUND = 1e9;

template <class T>
struct SegmentManager {
    set<tuple<int, int, T>> segs;
    T maxValue;
    SegmentManager() {}
    SegmentManager(T init, T maxValue) : maxValue(maxValue) {
        segs.emplace(-RBOUND, RBOUND, init);
    }
    tuple<int, int, T> containingSegment(int i) {
        assert(-RBOUND <= i && i <= RBOUND); // sanity check
        auto nextSeg = segs.lower_bound(tuple<int, int, T>(i, RBOUND + 1, maxValue));
        return *prev(nextSeg, 1);
    }
    void splitSegmentAt(int i, bool iOnLeft) {
        auto [l, r, v] = containingSegment(i);
        segs.erase(segs.find(tuple<int, int, T>(l, r, v)));
        int lsp = i, rsp = i + 1;
        if (!iOnLeft) { --lsp; --rsp; }
//        printf("split %d (%d) into %d %d %d %d\n", i, int(iOnLeft), l, lsp, rsp, r);
        if (l <= lsp) segs.emplace(l, lsp, v);
        if (rsp <= r) segs.emplace(rsp, r, v);
    }
    vector<T> setSegment(int i, int j, T v) {
        splitSegmentAt(i, false);
        splitSegmentAt(j, true);
        vector<T> valuesCut;
        auto cseg = segs.lower_bound(tuple<int, int, T>(i, -RBOUND - 1, maxValue));
        while (cseg != segs.end() && get<0>(*cseg) <= j) {
            valuesCut.push_back(get<2>(*cseg));
            segs.erase(cseg);
            cseg = segs.lower_bound(tuple<int, int, T>(i, -RBOUND - 1, maxValue));
        }
        segs.emplace(i, j, v);
        return valuesCut;
    }
    void debug() {
        /*
        cout << "== SEGMENT MANAGER CONTENTS" << endl;
        for (auto [l, r, v] : segs) cout << l << " " << r << " " << v << endl;
        cout << "== END" << endl;
        */
    }
};

int main() {
    int n, t; scanf("%d %d", &n, &t);
    vector<tuple<int, int, int>> segments;
    for (int i = 0; i < n; ++i) {
        int h, l, r; scanf("%d %d %d", &h, &l, &r);
        segments.emplace_back(h, l, r);
    }
    segments.emplace_back(0, -RBOUND, RBOUND);
    segments.emplace_back(t, -RBOUND, RBOUND);
    sort(begin(segments), end(segments));
    vector<vector<int>> fallTo(n + 2);
    SegmentManager<int> segm(-1, RBOUND + 1);
    auto naaabot = [&] (int i, int j) { // i has to be above j
        auto [ih, il, ir] = segments[i];
        auto [jh, jl, jr] = segments[j];
        return ih > jh && max(il, jl) < min(ir, jr);
    };
    auto overlap = [&] (int i, int j) {
        auto [ih, il, ir] = segments[i];
        auto [jh, jl, jr] = segments[j];
        if (!naaabot(i, j)) return 0;
        else return min(ir, jr) - max(il, jl);
    };
    auto harang = [&] (int i, int j, int k) {
        return (get<0>(segments[i]) > get<0>(segments[j]) && 
                get<0>(segments[j]) > get<0>(segments[k]))
            && naaabot(i, j) && naaabot(j, k);
    };
    for (int i = 0; i < n + 2; ++i) {
        auto [h, l, r] = segments[i];
//        printf("%d is %d %d %d\n", i, h, l, r);
        vector<int> cutSegments = segm.setSegment(l, r, i);
        vector<int> filteredcs; for (int v : cutSegments) if (v >= 0) filteredcs.push_back(v);
        for (int k = 0; k < filteredcs.size(); ++k) {
//            printf("%d sees %d\n", i, filteredcs[k]);
            if (k > 0 && harang(i, filteredcs[k-1], filteredcs[k])) continue;
            if (k + 1 < filteredcs.size()
                    && harang(i, filteredcs[k+1], filteredcs[k])) continue;
            fallTo[i].push_back(filteredcs[k]);
        }
        segm.debug();
    }
    vector<int> biggestFallTo(n + 2);
    biggestFallTo[n + 1] = 2 * RBOUND;
    for (int i = n + 1; i > 0; --i) {
        for (int v : fallTo[i]) biggestFallTo[v] = max(biggestFallTo[v],
                min(overlap(i, v), biggestFallTo[i]));
    }
    printf("%d\n", biggestFallTo[0]);
}