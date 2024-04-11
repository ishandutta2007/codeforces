#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        V<int> st(k, -1);
        bool ok = 1;
        rep(i, n) {
            int p = i % k;
            if (s[i] == '0') {
                if (st[p] != -1 && st[p] != 0) {
                    ok = 0;
                }
                st[p] = 0;
            } else if (s[i] == '1') {
                if (st[p] != -1 && st[p] != 1) {
                    ok = 0;
                }
                st[p] = 1;
            }
        }
        int c0 = 0, c1 = 0;
        rep(i, k) {
            if (st[i] == 0) {
                c0++;
            } else if (st[i] == 1) {
                c1++;
            }
        }
        if (c0 > k / 2 || c1 > k / 2) {
            ok = 0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}