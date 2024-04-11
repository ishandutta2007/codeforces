#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

template<typename T>
struct BIT {
    int n, lg;
    vector<T> bit;

    BIT(int _n) : n(_n), lg(__lg(n)), bit(n + 1) {}

    BIT(const vector<T> &a) : n((int) a.size()), lg(__lg(n)), bit(n + 1) {
        for (int i=1; i<=n; i++) {
            bit[i] += a[i-1];
            if (i + (i & -i) <= n)
                bit[i+(i&-i)] += bit[i];
        }
    }

    T query(int i) {
        T ret = 0;
        for (i++; i>0; i-=i&-i)
            ret += bit[i];
        return ret;
    }

    T query(int l, int r) {
        return l > r ? 0 : query(r) - query(l - 1);
    }

    void update(int i, T val) {
        for (i++; i<=n; i+=i&-i)
            bit[i] += val;
    }

    int kth(T k) {
        int ret = 0;
        for (int i=lg; i>=0; i--) {
            ret += 1 << i;
            if (ret <= n && bit[ret] < k)
                k -= bit[ret];
            else
                ret -= 1 << i;
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    map<int, uint32_t> mp;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<BIT<int>> bit(32, n);
    for (int i=0; i<n; i++) {
        if (!mp.count(a[i]))
            mp[a[i]] = rng();
        uint32_t mask = mp[a[i]];
        for (int j=0; j<32; j++)
            if (mask >> j & 1)
                bit[j].update(i, 1);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            if (!mp.count(x))
                mp[x] = rng();
            uint32_t mask = mp[a[i]], nmask = mp[x];
            for (int j=0; j<32; j++) {
                if (mask >> j & 1)
                    bit[j].update(i, -1);
                if (nmask >> j & 1)
                    bit[j].update(i, 1);
            }
            a[i] = x;
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            bool ok = true;
            for (int j=0; j<32; j++)
                ok &= bit[j].query(l, r) % k == 0;
            cout << (ok ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}