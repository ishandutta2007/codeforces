#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

const int N = 3e5 + 10;
int n;
int a[N];
int cnt[N];

struct Fenwick{
    int n;
    vector<ll> tree;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, ll val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
        // tree[pos] += val;
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    ll get(int l, int r) {
        chkmax(l, 0);
        chkmin(r, n - 1);
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

struct Node{
    ll modSum;
    ll modAdd;
    ll sum;
    Node() : modSum(0), modAdd(0), sum(0) {}
    Node getVal(int sz) const {
        Node ans;
        ans.sum = sum + modSum * sz + modAdd * ((ll)sz * (sz - 1) / 2);
        return ans;
    }
};

Node merge(const Node& a, const Node& b) {
    Node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

namespace SegmentTree{
    Node tree[4 * N];
    int myTree[N];
    void init() {}
    void push(int v, int szL) {
        tree[v * 2].modSum += tree[v].modSum;
        tree[v * 2].modAdd += tree[v].modAdd;
        tree[v * 2 + 1].modSum += tree[v].modSum + tree[v].modAdd * szL;
        tree[v * 2 + 1].modAdd += tree[v].modAdd;
        tree[v].modSum = 0;
        tree[v].modAdd = 0;
    }
    int upd(int v, int tl, int tr, int l, int r, ll modSum) {
        if (tl >= r || tr <= l) return 0;
        if (tl >= l && tr <= r) {
            tree[v].modAdd++;
            tree[v].modSum += modSum;
            return tr - tl;
        }
        int tm = (tl + tr) / 2;
        push(v, tm - tl);
        int szL = upd(v * 2, tl, tm, l, r, modSum);
        szL += upd(v * 2 + 1, tm, tr, l, r, modSum + szL);
        tree[v] = merge(tree[v * 2].getVal(tm - tl), tree[v * 2 + 1].getVal(tr - tm));
        return szL;
    }
    void upd(int l, int r) {
        chkmax(l, 0);
        chkmin(r, N - 1);
        if (l > r) return;
        upd(1, 0, N, l, r + 1, 0);
    }
    ll get(int v, int tl, int tr, int pos) {
        if (tl >= pos + 1 || tr <= pos) return 0;
        if (tl == tr - 1) {
            return (tree[v].getVal(tr - tl)).sum;
        }
        int tm = (tl + tr) / 2;
        push(v, tm - tl);
        ll ans = get(v * 2, tl, tm, pos) + get(v * 2 + 1, tm, tr, pos);
        tree[v] = merge(tree[v * 2].getVal(tm - tl), tree[v * 2 + 1].getVal(tr - tm));
        return ans;    
    }
    ll get(int pos) {
        return get(1, 0, N, pos);
    }
};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    Fenwick sum(N);
    Fenwick cnt(N);
    SegmentTree::init();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (ll)a[i] * cnt.get(a[i] + 1, N - 1);
        ans += sum.get(0, a[i] - 1);
        ans += SegmentTree::get(a[i]);
        for (int l = a[i], step = 1; l < N; l += a[i], ++step) {
            int r = l + a[i] - 1;
            chkmin(r, N - 1);
            ans += sum.get(l, r) - cnt.get(l, r) * a[i] * step;
        }  

        cout << ans << ' ';
        cnt.upd(a[i], 1);
        sum.upd(a[i], a[i]);
        for (int l = a[i]; l < N; l += a[i]) {
            SegmentTree::upd(l, l + a[i] - 1);
        }    
    }
    cout << '\n';
    return 0;
}