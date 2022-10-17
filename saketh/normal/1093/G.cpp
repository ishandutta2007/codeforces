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

template<typename T> struct seg_tree {
    int S;
    vector<T> value;

    seg_tree<T>(int S) : S(S) {
        value.resize(2 * S);
    }

    // Rebuilds all non-leaf layers of the tree in O(S)
    void rebuild() {
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    // Replaces the value at index i with v in O(logS)
    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while (i > 1) {
            i /= 2;
            value[i] = value[2 * i] + value[2 * i + 1];
        }
    }

    // Returns the sum of the values at indices [i, j] in O(logS)
    T query(int i, int j) {
        T res_left, res_right;
        for (i += S, j += S; i <= j; i /= 2, j /= 2) {
            if ((i&1) == 1) res_left = res_left + value[i++];
            if ((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct node {
    int lo = INT_MAX, hi = INT_MIN;
    node() {}
    node(int v) { lo = v, hi = v; }
    node(int l, int h) { lo = l, hi = h; }
    node operator + (const node& o) const {
        return node(min(lo, o.lo), max(hi, o.hi));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    int N, K;
    cin >> N >> K;

    vector<seg_tree<node>> st(16, seg_tree<node>(N));
    auto set = [&](int i, array<int, 5> v) {
        for (int m = 0; m < 16; m++) {
            int t = v[0];
            for (int i = 0; i < 4; i++) {
                if (m & (1 << i)) t += v[i + 1];
                else t -= v[i + 1];
            }
            st[m].upd(i, node(t));
        }
    };

    array<int, 5> pt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++)
            cin >> pt[j];
        set(i, pt);
    }

    int Q, t, i, l, r;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> t;
        if (t == 1) {
            cin >> i;
            for (int j = 0; j < K; j++)
                cin >> pt[j];
            set(i - 1, pt);
        } else {
            int ans = 0;
            cin >> l >> r;
            for (int m = 0; m < 16; m++) {
                node res = st[m].query(l - 1, r - 1);
                ans = max(ans, res.hi - res.lo);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}