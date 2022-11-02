#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
int n, q;
int a[N];

void read() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

struct Node{
    ll sum;
    int minVal;
    int mod;
    Node() {
        sum = 0;
        minVal = 0;
        mod = 0;
    }
    Node(ll _sum, int _minVal) {
        sum = _sum;
        minVal = _minVal;
        mod = 0;
    }    
};

Node merge(const Node& a, const Node& b) {
    return {a.sum + b.sum, min(a.minVal, b.minVal)};
}

namespace SegmentTree{
    int n;
    Node tree[4 * N];

    void build(int v, int tl, int tr, int* a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = Node(a[tl], a[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm, tr, a);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    void init(int _n, int* a) {
        n = _n;
        build(1, 0, n, a);
    }

    void push(int v) {
        if (tree[v].mod == 0) return;
        tree[v * 2].mod = tree[v].mod;
        tree[v * 2 + 1].mod = tree[v].mod;
        tree[v].mod = 0;
    }

    Node getVal(int v, int tl, int tr) {
        if (tree[v].mod == 0) return tree[v];
        return {(ll)(tr - tl) * tree[v].mod, tree[v].mod};
    }

    int find(int v, int tl, int tr, int l, int r, int val) {
        if (tl >= r || tr <= l) return -1;
        if (getVal(v, tl, tr).minVal > val) return -1;
        if (tl == tr - 1) return tl;
        push(v);
        int tm = (tl + tr) / 2;
        int ans = find(v * 2, tl, tm, l, r, val);
        if (ans == -1) {
            ans = find(v * 2 + 1, tm, tr, l, r, val);
        }
        tree[v] = merge(getVal(v * 2, tl, tm), getVal(v * 2 + 1, tm, tr));
        return ans;
    }

    int find(int l, int val) {
        return find(1, 0, n, l, n, val);
    }

    void upd(int v, int tl, int tr, int l, int r, int x) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            tree[v].mod = x;
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        upd(v * 2, tl, tm, l, r, x);
        upd(v * 2 + 1, tm, tr, l, r, x);
        tree[v] = merge(getVal(v * 2, tl, tm), getVal(v * 2 + 1, tm, tr));
    }

    void upd(int r, int x) {
        int l = find(0, x);
        if (l == -1 || l > r) return;
        upd(1, 0, n, l, r + 1, x);
    }

    ll getSum(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return 0;
        if (tl >= l && tr <= r) {
            return getVal(v, tl, tr).sum;
        }
        push(v);
        int tm = (tl + tr) / 2;
        ll ans = getSum(v * 2, tl, tm, l, r) + getSum(v * 2 + 1, tm, tr, l, r);
        tree[v] = merge(getVal(v * 2, tl, tm), getVal(v * 2 + 1, tm, tr));
        return ans;
    }

    ll getSum(int l, int r) {
        return getSum(1, 0, n, l, r + 1);
    }

    int get(int v, int tl, int tr, ll sum) {
        if (sum <= 0) return -1;
        if (tl == tr - 1) {
            if (getVal(v, tl, tr).sum <= sum) {
                return tl;
            } else {
                return -1;
            }
        }
        push(v);
        int tm = (tl + tr) / 2;
        int ans = get(v * 2 + 1, tm, tr, sum - getVal(v * 2, tl, tm).sum);
        if (ans == -1) {
            ans = get(v * 2, tl, tm, sum);
        }
        tree[v] = merge(getVal(v * 2, tl, tm), getVal(v * 2 + 1, tm, tr));
        return ans;   
    }

    int get(int l, ll sum) {
        sum += getSum(0, l - 1);
        int fans = get(1, 0, n, sum);
        return fans - l + 1;
    }
}

void upd() {
    int r, x;
    cin >> r >> x;
    --r;
    SegmentTree::upd(r, x);
}

void get() {
    int ans = 0;
    int l, sum;
    cin >> l >> sum;
    --l;
    while (true) {
        int pos = SegmentTree::find(l, sum);
        if (pos == -1) break;
        l = pos;
        int fans = SegmentTree::get(l, sum);
        sum -= SegmentTree::getSum(l, l + fans - 1);
        ans += fans;
        l += fans;
    }
    cout << ans << '\n';
}

void run() {
    SegmentTree::init(n, a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            upd();
        } else {
            get();
        }
    }
}

void write() {

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}