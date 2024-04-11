#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 1e18l + 666 : 1e9 + 666);
const ll INFll = 1e18 + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline constexpr int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

struct Node {
    int ln, first_elem, last_elem, inc_pref, inc_suff;
    ll ans;

    Node(): ln(0), first_elem(0), last_elem(0), inc_pref(0), inc_suff(0), ans(0) {}
    Node(int val): ln(1), first_elem(val), last_elem(val), inc_pref(1), inc_suff(1), ans(1) {}
    Node(const Node&) = default;

    Node& operator=(const Node&) = default;

    static Node Merge(const Node& l, const Node& r) {
        Node res;
        res.ln = l.ln + r.ln;
        res.first_elem = l.first_elem;
        res.last_elem = r.last_elem;
        res.inc_pref = l.inc_pref;
        res.inc_suff = r.inc_suff;
        res.ans = l.ans + r.ans;
        if (l.last_elem <= r.first_elem) {
            if (l.inc_pref == l.ln) {
                res.inc_pref += r.inc_pref;
            }
            if (r.inc_suff == r.ln) {
                res.inc_suff += l.inc_suff;
            }
            res.ans += 1ll * l.inc_suff * r.inc_pref;
        }
        return res;
    }
};

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(const vector<int>& v): n(len(v)) {
        while (n & (n - 1)) ++n;
        tree.resize(2 * n - 1);
        for (int i = 0; i < len(v); ++i) {
            tree[i + n - 1] = Node(v[i]);
        }
        for (int i = n - 2; i > -1; --i) {
            tree[i] = Node::Merge(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void update(int idx, int val) {
        idx += n - 1;
        tree[idx] = Node(val);
        while (idx > 0) {
            idx = (idx - 1) >> 1;
            tree[idx] = Node::Merge(tree[2 * idx + 1], tree[2 * idx + 2]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) const {
        if (l >= tr || tl >= r) {
            return {};
        }
        if (tl >= l && tr <= r) {
            return tree[v];
        }
        int mid = (tl + tr) >> 1;
        return Node::Merge(
            query(2 * v + 1, tl, mid, l, r),
            query(2 * v + 2, mid, tr, l, r)
        );
    }

    ll query(int l, int r) const {
        return query(0, 0, n, l, r).ans;
    }
};

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    SegTree t(a);
    for (int i = 0; i < m; ++i) {
        int tp, l, r;
        cin >> tp >> l >> r;
        --l;
        if (tp == 1) {
            t.update(l, r);
        } else {
            cout << t.query(l, r) << '\n';
        }
    }
}