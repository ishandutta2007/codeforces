#include <vector>
#include <limits>
#include <cassert>
#include <algorithm>

template<typename T, typename AssociativeOperation, typename Timestamp = int>
struct segment_tree_persistent {
    struct node {
        T v;
        int left, right;
    };
    struct snapshot {
        Timestamp t;
        int root;
        int data_size;
        bool operator < (const snapshot &o) const { return t < o.t; }
    };

    int SZ;
    T identity;
    AssociativeOperation TT;
    std::vector<node> data;
    std::vector<snapshot> history;

    segment_tree_persistent() {}

    segment_tree_persistent(int _SZ, T _identity, AssociativeOperation _TT) : identity(_identity), TT(_TT) {
        SZ = 1 << (32 - __builtin_clz(_SZ - 1));
        assert(SZ >= _SZ && __builtin_popcount(SZ) == 1);

        data.push_back({ identity, -1, -1 });
        for (int loc = 1; loc <= __builtin_ctz(SZ); loc++)
            data.push_back({ TT(data[loc - 1].v, data[loc - 1].v), loc - 1, loc - 1 });

        history.push_back({ std::numeric_limits<Timestamp>::min(), int(data.size()) - 1, int(data.size()) });
    }

private:
    int modify_leaf(int i, T v, int loc, int L, int R, int immutable, bool overwrite) {
        node updated;
        if (R - L == 1) {
            updated = { overwrite ? v : TT(data[loc].v, v), -1, -1 };
        } else {
            int M = L + (R - L) / 2;
            int left  = i <  M ? modify_leaf(i, v, data[loc].left,  L, M, immutable, overwrite) : data[loc].left;
            int right = M <= i ? modify_leaf(i, v, data[loc].right, M, R, immutable, overwrite) : data[loc].right;
            updated = { TT(data[left].v, data[right].v), left, right };
        }
        if (loc < immutable) {
            loc = int(data.size());
            data.push_back(updated);
        } else {
            data[loc] = updated;
        }
        return loc;
    }

    void modify_leaf(int i, T v, Timestamp t, bool overwrite) {
        int current_root = history.back().root;
        if (history.back().t == t) history.pop_back();

        int immutable = history.back().data_size;
        int updated_root = modify_leaf(i, v, current_root, 0, SZ, immutable, overwrite);
        history.push_back({ t, updated_root, int(data.size()) });
    }

    T accumulate(int i, int j, T init, int loc, int L, int R) const {
        if (L == i && j == R) {
            init = TT(init, data[loc].v);
        } else {
            int M = L + (R - L) / 2;
            if (i < M) init = accumulate(i, std::min(j, M), init, data[loc].left,  L, M);
            if (M < j) init = accumulate(std::max(i, M), j, init, data[loc].right, M, R);
        }
        return init;
    }

public:
    // Assigns v at index i during moment t
    void assign(int i, T v, Timestamp t) {
        assert(0 <= i && i < SZ && history.back().t <= t);
        modify_leaf(i, v, t, true);
    }

    // Replaces the current value at index i with TT(current value, v) during moment t
    void combine_and_assign(int i, T v, Timestamp t) {
        assert(0 <= i && i < SZ && history.back().t <= t);
        modify_leaf(i, v, t, false);
    }

    // Accumulates the elements at indices in [first, last) as they were before t (after all assignments with t' < t)
    T accumulate(int first, int last, Timestamp t) const {
        if (first >= last) return identity;
        assert(0 <= first && last <= SZ);
        int root_before_t = std::prev(std::lower_bound(history.begin(), history.end(), snapshot{ t, -1, -1 }))->root;
        return accumulate(first, last, identity, root_before_t, 0, SZ);
    }
};

// {{{ data_structures/segment_tree_persistent.cpp }}}

#include <functional>
#include <vector>
#include <algorithm>
#include <cassert>

template<typename T>
struct count_distinct_in_range {
    segment_tree_persistent<int, std::plus<int>> st;

    template<typename InputIterator>
    count_distinct_in_range(InputIterator first, InputIterator last, int copies_allowed = 1) {
        assert(copies_allowed >= 1);

        std::vector<std::remove_reference_t<decltype(*first)>> universe(first, last);
        std::sort(universe.begin(), universe.end());
        universe.erase(std::unique(universe.begin(), universe.end()), universe.end());

        std::vector<std::vector<int>> occurrences(universe.size());

        int SZ = 0;
        for (InputIterator iter = first; iter != last; iter++) {
            int val = int(lower_bound(universe.begin(), universe.end(), *iter) - universe.begin());
            occurrences[val].push_back(SZ);
            SZ++;
        }

        st = decltype(st)(SZ, 0, std::plus<int>());

        std::vector<int> successor(SZ, -1);

        for (int i = 0; i < universe.size(); i++) {
            for (int j = 0; j < std::min(copies_allowed, int(occurrences[i].size())); j++)
                st.assign(occurrences[i][j], 1, -1);

            for (int j = 0; j + copies_allowed < int(occurrences[i].size()); j++)
                successor[occurrences[i][j]] = occurrences[i][j + copies_allowed];
        }

        for (int i = 0; i < SZ; i++)
            if (successor[i] != -1)
                st.assign(successor[i], 1, i);
    }

    /* Number of elements at indices in [L, R) counting only
     * the first 'copies_allowed' appearances of each distinct value.
     */
    int get_count(int L, int R) {
        return st.accumulate(L, R, L);
    }
};

#include <cstdio>
#include <vector>

// {{{ misc/count_distinct_in_range }}}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    std::vector<int> a(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    count_distinct_in_range<int> cd(a.begin(), a.end(), K);

    int Q, last = 0;
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int l = (x + last) % N;
        int r = (y + last) % N;
        if (l > r) std::swap(l, r);

        printf("%d\n", last = cd.get_count(l, r + 1));
    }

    return 0;
}