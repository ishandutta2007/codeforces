#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T> struct binary_indexed_tree {
    int S;
    vector<T> table;

    binary_indexed_tree<T>(int _S = 0) : S(_S) {
        table.resize(S+1);
    }

    // Adds v to the element at index i
    void add(int i, T v) {
        for (i++; i <= S; i += i&-i)
            table[i] = table[i] + v;
    }

    void replace(int i, T v) {
        add(i, v - sum(i, i+1));
    }

    // Returns the sum of the elements at indices [0, i)
    T sum(int i) const {
        T res = T();
        for (; i; i -= i&-i)
            res = res + table[i];
        return res;
    }

    // Returns the sum of the elements at indices [l, r)
    T sum(int l, int r) const {
        return sum(r) - sum(l);
    }

    /*
     * Returns in O(logS) the first i in [0, S] such that comp(sum(i)) is true.
     * Returns -1 if no such i exists.
     * Requires that comp(sum(i)) is non-decreasing in i.
     * The empty prefix is considered to have sum equal to T's default value.
     */
    int lower_bound(const auto& comp) const {
        T cur = T();
        if (comp(cur)) return 0;

        int inx = 0;
        for (int i = 31 - __builtin_clz(S); i >= 0; i--) {
            int nxt = inx + (1 << i);
            if (nxt <= S && !comp(cur + table[nxt])) {
                inx = nxt;
                cur = cur + table[nxt];
            }
        }

        return inx < S ? inx + 1 : -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    binary_indexed_tree<ll> sh(N);

    vi pow(N);
    for (int i = 0; i < N; i++) {
        cin >> pow[i];
        sh.add(i, pow[i]);
    }

    for (int q = 0, i, v; q < Q; q++) {
        cin >> i >> v;
        --i;

        sh.replace(i, pow[i] = v);

        int used = 1;
        ll sum = sh.sum(used);

        while (true) {
            if (2 * pow[used - 1] == sum) { cout << used << "\n"; break; }

            auto pred = [&sum](ll tot) { return tot >= 2 * sum; };
            int jump = sh.lower_bound(cref(pred));
            if (jump == -1) { cout << "-1\n"; break; }

            used = jump;
            sum = sh.sum(used);
        }
    }

    return 0;
}