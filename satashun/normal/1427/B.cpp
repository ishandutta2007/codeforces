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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        V<pii> vec;
        rep(i, n) {
            if (vec.size() && vec.back().fi == s[i]) {
                vec.back().se++;
            } else {
                vec.eb(s[i], 1);
            }
        }
        // debug(vec);

        int l = 0;
        rep(i, n) if (s[i] == 'L') l++;
        chmin(k, l);
        int cur = 0;
        rep(i, n) if (s[i] == 'W') {
            if (i > 0 && s[i - 1] == 'W')
                cur += 2;
            else
                cur++;
        }
        int ans = 0;
        if (k > 0) {
            if (l == n) {
                ans = 1 + 2 * (k - 1);
            } else {
                ans = 2 * k;
                V<int> vw;
                rep(i, SZ(vec)) {
                    if (i > 0 && i + 1 < SZ(vec) && vec[i].fi == 'L') {
                        vw.pb(vec[i].se);
                    }
                }
                sort(ALL(vw));
                int s = 0;
                rep(i, vw.size()) {
                    if (s + vw[i] <= k) {
                        s += vw[i];
                        ans++;
                    }
                }
            }
        }
        cout << cur + ans << endl;
    }
    return 0;
}