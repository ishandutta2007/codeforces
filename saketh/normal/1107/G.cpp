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

struct extr {
    ll lo = LLONG_MAX, hi = LLONG_MIN;
    extr() {}
    extr(ll v) : lo(v), hi(v) {}
    extr(ll l, ll h) : lo(l), hi(h) {}
    extr operator + (const extr& o) {
        return extr(min(lo, o.lo), max(hi, o.hi));
    }
};

struct union_find {
    vi P, R, S, L, H;

    union_find(int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1);
        L.resize(N), H.resize(N);
        for (int i = 0; i < N; i++)
            P[i] = L[i] = H[i] = i;
    }

    int rep(int i) {
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if(a == b) return false;
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if(R[a] == R[b]) R[a]++;
        L[a] = min(L[a], L[b]);
        H[a] = max(H[a], H[b]);
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A;
    cin >> N >> A;

    ll ans = 0;

    vi d(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> d[i] >> c[i];
        c[i] = A - c[i];
        ans = max(ans, ll(c[i]));
    }

    vector<extr> pref(N + 1);
    pref[0] = extr(0);
    for (int i = 1; i <= N; i++)
        pref[i] = extr(pref[i-1].lo + c[i-1]);
    sparse_table<extr> st(pref);

    vi gaps(N - 1);
    for (int i = 0; i < N - 1; i++)
        gaps[i] = i;
    sort(all(gaps), [&d](int a, int b) {
        return abs(d[a+1] - d[a]) < abs(d[b+1] - d[b]);
    });

    union_find uf(N);
    for (int i : gaps) {
        ll gap = d[i+1] - d[i];

        int l = uf.L[uf.rep(i)];
        int h = uf.H[uf.rep(i+1)];
        ll add = st.query(i+2, h+1).hi;
        ll sub = st.query(l, i).lo;
        ans = max(ans, add - sub - gap * gap);

        uf.unio(i, i+1);
    }

    cout << ans << endl;

    return 0;
}