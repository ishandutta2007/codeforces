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
 * Supports O(logS) range queries and updates on an array of items.
 * Requires that type T's combine operator is associative and
 * that T() + t = t + T() = t for all T t.
 */
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
    int inx, val;
    ll sum = 0;
    node(int inx = -1, int val = 0) : inx(inx), val(val), sum(val) {}
    node operator + (const node& o) const {
        if (inx == -1) return o;
        if (o.inx == -1) return *this;

        node res = (val > o.val) ? *this : o;
        res.sum = sum + o.sum;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, v;
    cin >> N >> M;
    seg_tree<node> st(N);

    for (int i = 0; i < N; i++) {
        cin >> v;
        st.value[st.S + i] = node(i, v);
    }
    st.rebuild();

    int t, l, r, k, x;
    for (int q = 0; q < M; q++) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r;
            cout << st.query(l - 1, r - 1).sum << "\n";
        } else if (t == 2) {
            cin >> l >> r >> x;
            while (true) {
                node lrs = st.query(l - 1, r - 1);
                if (lrs.val >= x) {
                    st.upd(lrs.inx, node(lrs.inx, lrs.val % x));
                } else break;
            }
        } else {
            cin >> k >> x;
            st.upd(k - 1, node(k - 1, x));
        }
    }

    return 0;
}