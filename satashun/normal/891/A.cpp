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
#define ALL(c) (c).begin(), (c).end()

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

const int INF = TEN(9);

int main() {
    int n;
    cin >> n;
    V<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = INF;
    int fr = n + 10, en = -1;

    int one = 0;
    rep(i, n) one += (a[i] == 1);
    if (one) {
        cout << n - one << endl;
        return 0;
    }

    rep(i, n) {
        if (a[i] != 1) {
            chmin(fr, i);
            chmax(en, i);
        }
    }
    rep(i, n) {
        int d = a[i];
        for (int j = i; j < n; ++j) {
            d = __gcd(d, a[j]);
            if (d == 1) {
                int w = (j - i) * 2;
                if (fr < i) {
                    w += i - fr;
                }
                if (en > j) {
                    w += en - j;
                }
                chmin(ans, w);
            }
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}