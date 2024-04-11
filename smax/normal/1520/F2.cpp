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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int SZ = 14;

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
        for (; i>0; i-=i&-i)
            ret += bit[i];
        return ret;
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
    }

    void update(int i, T val) {
        for (; i<=n; i+=i&-i)
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
        return ret + 1;
    }
};

int queries = 0;

int query(int l, int r) {
    assert(++queries <= 60000);
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int ret;
    cin >> ret;
    assert(ret != -1);
    return r - l + 1 - ret; // returns number of 0s instead
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // had issues with RE on interactive with Python for some reason :(

    int n, t;
    cin >> n >> t;
    BIT<int> bit({});
    for (int rep=0; rep<t; rep++) {
        int k;
        cin >> k;

        if (rep == 0) {
            vector<int> blocks;
            for (int i=0; i<n; i+=SZ)
                blocks.push_back(query(i, min(i + SZ - 1, n - 1)));
            bit = BIT<int>(blocks);
        }

        int b = bit.kth(k), l = (b - 1) * SZ, r = min(b * SZ, n);
        while (l < r) {
            int m = (l + r) / 2;
            if (query(0, m) >= k)
                r = m;
            else
                l = m + 1;
        }
        cout << "! " << l + 1 << endl;
        bit.update(b, -1);
    }

    return 0;
}