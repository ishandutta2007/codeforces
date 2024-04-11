#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

int getInv(int x) {
    return binpow(x, MOD - 2);
}

const int N = 1e6 + 228;
int f[N], rf[N];

void initCnk() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
        rf[i] = getInv(f[i]);
    }
}

int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul(f[n], mul(rf[k], rf[n - k]));
}

struct Seg{
    int l, r;
};

int n, k;
vector<Seg> a;

void read() {
    cin >> n >> k;
    a.resize(n);
    for (auto& [l, r] : a) {
        cin >> l >> r;
    }
}

struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, int val) {
        if (pos < 0 || pos >= n) return;
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    void upd(int l, int r, int val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    int get(int pos) {
        int ans = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            ans += tree[pos];
        }
        return ans;
    }
};

Fenwick tree;

void build() {
    vector<int> coord;
    for (auto [l, r] : a) {
        coord.push_back(l);
        coord.push_back(r);
    }
    sort(all(coord));
    coord.resize(unique(all(coord)) - coord.begin());
    for (auto& [l, r] : a) {
        l = lower_bound(all(coord), l) - coord.begin();
        r = lower_bound(all(coord), r) - coord.begin();
    }
    tree = Fenwick(coord.size());
    sort(all(a), [] (const Seg& a, const Seg& b) {
        return a.r < b.r;
    });
    /*cout << "a = " << endl;
    for (auto i : a) {
        cout << "l = " << i.l << " r = " << i.r << endl;
    }*/
    for (auto [l, r] : a) {
        tree.upd(l, r, 1);
    }
}

int ans;

void run() {
    build();
    ans = 0;
    for (auto [l, r] : a) {
        tree.upd(l, r, -1);
        ans = add(ans, cnk(tree.get(r), k - 1));
    }
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    initCnk();
    read();
    run();
    write();
    return 0;
}