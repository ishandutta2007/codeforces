// segment_tree_lazy {{{
#include <vector>
#include <cassert>

template<typename T, typename U,
    typename TAssociativeCombineFunction,
    typename UAssociativeCombineFunction,
    typename UApplicator>
struct segment_tree_lazy {
    int SZ;
    T t_identity;
    U u_identity;
    TAssociativeCombineFunction TT;
    UAssociativeCombineFunction UU;
    UApplicator UT;

    std::vector<T> data;
    std::vector<bool> has_update;
    std::vector<U> updates;

    segment_tree_lazy() {}

    segment_tree_lazy(int _SZ, T _t_identity, U _u_identity,
            TAssociativeCombineFunction _TT, UAssociativeCombineFunction _UU, UApplicator _UT)
            : SZ(_SZ), t_identity(_t_identity), u_identity(_u_identity), TT(_TT), UU(_UU), UT(_UT) {
        data.assign(2 * SZ, t_identity);
        has_update.assign(SZ, false);
        updates.assign(SZ, u_identity);
    }

    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[SZ + i] = fn(i);
        for (int i = SZ - 1; i; i--)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
        has_update.assign(SZ, false);
        updates.assign(SZ, u_identity);
    }

private:
    void apply_update(int i, const U &u) {
        data[i] = UT(u, data[i]);
        if (i < SZ) {
            has_update[i] = true;
            updates[i] = UU(u, updates[i]);
        }
    }

    void propagate_ancestor_updates(int i) {
        for (int ht = 31 - __builtin_clz(i); ht > 0; ht--) {
            int anc = i >> ht;
            if (has_update[anc]) {
                apply_update(2 * anc, updates[anc]);
                apply_update(2 * anc + 1, updates[anc]);
                has_update[anc] = false;
                updates[anc] = u_identity;
            }
        }
    }

    void recompute_ancestors(int i) {
        for (i /= 2; i; i /= 2)
            data[i] = UT(updates[i], TT(data[2 * i], data[2 * i + 1]));
    }

    void modify_leaf(int i, T v, bool overwrite) {
        i += SZ;
        propagate_ancestor_updates(i);
        data[i] = overwrite ? v : TT(data[i], v);
        recompute_ancestors(i);
    }

public:
    // Assigns v at index i
    void assign(int i, T v) {
        modify_leaf(i, v, true);
    }

    // Replaces the current value at index i with TT(current value, v)
    void combine_and_assign(int i, T v) {
        modify_leaf(i, v, false);
    }

    // Applies update u to the elements at indices in [first, last)
    void apply_update(int first, int last, U u) {
        first += SZ, last += SZ;
        propagate_ancestor_updates(first);
        propagate_ancestor_updates(last - 1);
        for (int f = first, l = last; f < l; f /= 2, l /= 2) {
            if (f&1) apply_update(f++, u);
            if (l&1) apply_update(--l, u);
        }
        recompute_ancestors(first);
        recompute_ancestors(last - 1);
    }

    // Accumulates the elements at indices in [first, last)
    T accumulate(int first, int last) {
        first += SZ, last += SZ;
        propagate_ancestor_updates(first);
        propagate_ancestor_updates(last - 1);

        T left = t_identity, right = t_identity;
        for (int f = first, l = last; f < l; f /= 2, l /= 2) {
            if (f&1) left = TT(left, data[f++]);
            if (l&1) right = TT(data[--l], right);
        }
        return TT(left, right);
    }

    // Returns the current value at index i
    T read(int i) {
        i += SZ;
        propagate_ancestor_updates(i);
        return data[i];
    }
};
// }}}

#include <cstdio>
#include <vector>
#include <cstdint>
#include <functional>
#include <cstring>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    using std_min_type = const int64_t&(*)(const int64_t&, const int64_t&);

    segment_tree_lazy<int64_t, int64_t, std_min_type, plus<int64_t>, plus<int64_t>>
        st(N, 1e12, 0, min<int64_t>, plus<int64_t>(), plus<int64_t>());

    st.assign([](int i) { int v; scanf("%d", &v); return v; });

    int Q;
    scanf("%d\n", &Q);

    char s[256];

    for (int q = 0; q < Q; q++) {
        fgets(s, 256, stdin);

        char *p = strtok(s, " ");
        int lf = atoi(p);

        p = strtok(NULL, " ");
        int rg = atoi(p);

        p = strtok(NULL, " ");
        if (p != NULL) {
            int v = atoi(p);
            if (lf <= rg) {
                st.apply_update(lf, rg + 1, v);
            } else {
                st.apply_update(lf, N, v);
                st.apply_update(0, rg + 1, v);
            }
        } else {
            int64_t res;
            if (lf <= rg)
                res = st.accumulate(lf, rg + 1);
            else
                res = min(st.accumulate(lf, N), st.accumulate(0, rg + 1));
            printf("%jd\n", res);
        }
    }

    return 0;
}