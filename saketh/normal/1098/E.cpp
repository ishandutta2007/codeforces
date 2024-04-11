#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
 * Supports O(1) range queries on an immutable array of items.
 * Requires that type T's combine operator is associate, commutative,
 * and idempotent.
 */
template<typename T> struct sparse_table {
    int S, L;
    vector<T> table;
    T& entry(int l, int i) { return table[l * S + i]; }

    // Constructs the table in O(S log S) time and memory
    sparse_table(const vector<T>& elts = {}) : S(elts.size()) {
        L = 32 - __builtin_clz(S);
        table.resize(L * S);
        copy(all(elts), table.begin());

        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < S; i++) {
                entry(l + 1, i) = entry(l, i);
                if (i + (1 << l) < S)
                    entry(l + 1, i) = entry(l + 1, i) + entry(l, i + (1 << l));
            }
        }
    }

    // Returns elts[i] + ... + elts[j] in O(1)
    T query(int i, int j) {
        int l = 31 - __builtin_clz(j - i + 1);
        return entry(l, i) + entry(l, j - (1 << l) + 1);
    }
};

struct elt {
    int v;
    elt(int v = 0) : v(v) { }
    elt operator + (const elt& o) const {
        return elt(__gcd(v, o.v));
    }
};

const int MAXV = 1e5 + 1;

vll count_gcd_freq(int N, vi& a) {
    vector<elt> g(N);
    for (int i = 0; i < N; i++)
        g[i] = elt(a[i]);
    sparse_table<elt> st(g);

    vll freq(MAXV);
    for (int i = 0; i < N; i++) {
        for (int b = i; b < N; ) {
            int v = st.query(i, b).v;
            int e = b, lo = b + 1, hi = N - 1;
            while (lo <= hi) {
                int mi = (lo + hi) / 2;
                if (v == st.query(i, mi).v) {
                    e = mi;
                    lo = mi + 1;
                } else {
                    hi = mi - 1;
                }
            }
            freq[v] += e - b + 1;
            b = e + 1;
        }
    }
    return freq;
}

namespace from_neal {
    // Counts x, y >= 0 such that Ax + By <= C.
    long long count_triangle(long long A, long long B, long long C) {
        if (C < 0) return 0;
        if (A > B) swap(A, B);
        long long p = C / B;
        long long k = B / A;
        long long d = (C - p * B) / A;
        return count_triangle(B - k * A, A, C - A * (k * p + d + 1)) + (p + 1) * (d + 1) + k * p * (p + 1) / 2;
    }

    // Counts 0 <= x < RA, 0 <= y < RB such that Ax + By <= C.
    long long count_triangle_rectangle_intersection(long long A, long long B, long long C, long long RA, long long RB) {
        if (C < 0) return 0;
        if (C >= A * RA + B * RB) return RA * RB;
        if (RA <= 0 || RB <= 0) return 0;
        return count_triangle(A, B, C) - count_triangle(A, B, C - A * RA) - count_triangle(A, B, C - B * RB);
    }
};

ll count_subarray_leq(const vll& b, ll T) {
    ll res = 0;

    for (int i = 1; i < MAXV; i++) {
        ll lim = min(b[i], T / i);
        ll rem = b[i] - lim;
        res += b[i] * (b[i] + 1) / 2 - rem * (rem + 1) / 2;
    }

    ll tot = 0, elts = 0;
    for (int i = 1, j = 1; i < MAXV; i++) {
        tot -= i * b[i];
        elts -= b[i];
        if (i < j) res += b[i] * elts;

        while (j < MAXV) {
            if (i < j)
                res += from_neal::count_triangle_rectangle_intersection(
                        i, j, T - tot - i - j, b[i], b[j]);

            if (tot + j * b[j] <= T) {
                tot += j * b[j];
                elts += b[j];
                j++;
            } else {
                break;
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vll b = count_gcd_freq(N, a);

    ll B = N * 1ll * (N + 1) / 2;
    ll C = B * (B + 1) / 2;

    ll ans = 0, lo = 1, hi = 0;
    for (int i = 0; i < MAXV; i++)
        hi += i * b[i];

    while (lo <= hi) {
        ll mi = (lo + hi) / 2;
        if (count_subarray_leq(b, mi - 1) <= (C - 1) / 2) {
            ans = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    cout << ans << endl;

    return 0;
}