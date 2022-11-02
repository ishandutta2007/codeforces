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

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) return a + MOD;
    return a;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick() {}
    Fenwick(int _n) : n(_n), tree(n, 0) {}

    void upd(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] = add(tree[pos], val);
        }    
    }

    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans = add(ans, tree[r]);
        }
        return ans;
    }
};

void compress(vector<int>& a) {
    vector<int> c = a;
    sort(all(c));
    c.resize(unique(all(c)) - c.begin());
    for (auto& i : a) i = lower_bound(all(c), i) - c.begin();
}

vector<int> calcL(vector<int> a) {
    compress(a);
    int n = a.size();
    Fenwick st((*max_element(all(a))) + 1);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i){
        ans[i] = add(st.get(a[i] - 1), 1);
        st.upd(a[i], ans[i]);
    }
    return ans;
}

vector<int> calcR(vector<int> a) {
    for (auto& i : a) i = -i;
    reverse(all(a));
    vector<int> r = calcL(a);
    reverse(all(r));
    return r;
}

int calc(vector<int>& a, vector<int>& l, vector<int>& r) {
    for (auto& i : a) i = -i;
    compress(a);
    reverse(all(a));
    reverse(all(l));
    reverse(all(r));

    int n = a.size();
    Fenwick st((*max_element(all(a))) + 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int curR = i == 0 ? 1 : st.get(a[i] - 1);
        ans = add(ans, mul(l[i], sub(r[i], curR)));
        st.upd(a[i], curR);
    }   
    return ans;
}

int calc(vector<int>& a, vector<int>& l, vector<int>& r, vector<int>& id) {
    vector<int> realA, realL, realR;
    for (auto i : id) {
        realA.push_back(a[i]);
        realL.push_back(l[i]);
        realR.push_back(r[i]);
    }
    return calc(realA, realL, realR);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vin(a);
    vector<int> l = calcL(a);
    vector<int> r = calcR(a);
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&] (int i, int j) {
        return a[i] < a[j];
    });
    int pos = 0;
    int curMax = -1;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (curMax >= a[i]) continue;
        curMax = a[i];
        vector<int> id;
        while (pos < n && a[order[pos]] < curMax) {
            if (order[pos] < i) {
                id.push_back(order[pos]);
            }
            ++pos;
        }
        id.push_back(i);
        sort(all(id));
        ans = add(ans, calc(a, l, r, id));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}