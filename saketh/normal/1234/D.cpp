// Problem: https://codeforces.com/problemset/problem/1234/D

#include <iostream>
using namespace std;

// {{{ data_structures/segment_tree }}}

// segment_tree {{{
#include <vector>
#include <cassert>

template<typename T, typename AssociativeOperation>
struct segment_tree {
    int SZ;
    T identity;
    AssociativeOperation TT;
    std::vector<T> data;

    segment_tree() {}

    segment_tree(int _SZ, T _identity, AssociativeOperation _TT)
			: SZ(_SZ), identity(_identity), TT(_TT) {
        data.resize(2 * SZ, identity);
    }

    // Returns the value at index i
    const T& operator[](int i) const {
        assert(0 <= i && i < SZ);
        return data[SZ + i];
    }

    // Assigns fn(i) at index i for each i in [0, SZ)
    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[SZ + i] = fn(i);
        for (int i = SZ - 1; i; i--)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
    }

    // Assigns v at index i
    void assign(int i, T v) {
        assert(0 <= i && i < SZ);
        data[i += SZ] = v;
        for (i /= 2; i; i /= 2)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
    }

    // Returns the result of a left fold of the elements at indices in [first, last) over TT
    T accumulate(int first, int last) const {
        assert(0 <= first && last <= SZ);
        T left = identity, right = identity;
        for (first += SZ, last += SZ; first < last; first /= 2, last /= 2) {
            if (first & 1) left  = TT(left, data[first++]);
            if (last  & 1) right = TT(data[--last], right);
        }
        return TT(left, right);
    }
};
// }}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    segment_tree<int, bit_or<int>> st(s.size(), 0, bit_or<int>());
    st.assign([&s](int i) { return 1 << (s[i] - 'a'); });

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            char c;
            cin >> pos >> c;

            st.assign(pos - 1, 1 << (c - 'a'));
        } else {
            int l, r;
            cin >> l >> r;

            cout << __builtin_popcount(st.accumulate(l - 1, r)) << "\n";
        }
    }

    return 0;
}