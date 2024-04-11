#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

template<typename T>
struct BIT {
    int n;
    vector<T> bit;

    BIT(int _n) : n(_n), bit(n + 1) {}

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
};

vector<int> conv(const vector<int> &a) {
    int n = a.size();
    BIT<int> bit(n);
    vector<int> ret(n);
    for (int i=0; i<n; i++) {
        ret[i] = a[i] - bit.query(a[i]);
        bit.update(a[i] + 1, 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i=0; i<n; i++)
        cin >> p[i];
    for (int i=0; i<n; i++)
        cin >> q[i];

    vector<int> a = conv(p), b = conv(q), c(n);
    int carry = 0;
    for (int i=n-1; i>=0; i--) {
        c[i] = a[i] + b[i] + carry;
        carry = 0;
        if (c[i] >= n - i) {
            carry = c[i] / (n - i);
            c[i] %= n - i;
        }
    }

    BIT<int> bit(n);
    for (int i=0; i<n; i++) {
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2, ord = m - bit.query(m + 1);
            if (ord >= c[i])
                r = m;
            else
                l = m + 1;
        }
        cout << l << " ";
        bit.update(l + 1, 1);
    }
    cout << "\n";

    return 0;
}