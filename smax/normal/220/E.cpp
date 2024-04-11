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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n), sorted;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sorted.push_back(a[i]);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (int &x : a)
        x = int(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin()) + 1;

    BIT<int> bitL(n), bitR(n);
    long long cnt = 0;

    auto add = [&] (int x, bool s = false) -> void {
        cnt += bitL.query(x + 1, n) + bitR.query(x - 1);
        if (s) bitR.update(x, 1);
        else bitL.update(x, 1);
    };

    auto rem = [&] (int x) -> void {
        cnt -= bitL.query(x + 1, n) + bitR.query(x - 1);
        bitR.update(x, -1);
    };

    long long ret = 0;
    for (int i=n-1; i>0; i--)
        add(a[i], true);
    for (int i=0, j=1; i<n; i++) {
        if (i == j)
            rem(a[j++]);
        add(a[i]);
        while (j < n && cnt > k)
            rem(a[j++]);
        ret += n - j;
    }
    cout << ret << "\n";

    return 0;
}