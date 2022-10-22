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

const int maxn = 4010;
bool dp[maxn];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int TC;
    cin >> TC;

    while (TC--) {
        int n;
        cin >> n;
        V<int> vec(n * 2);
        rep(i, n * 2) cin >> vec[i], --vec[i];

        V<pii> maxi(n * 2 + 1);
        maxi[0] = mp(-1, -1);
        rep(i, n * 2) maxi[i + 1] = max(maxi[i], mp(vec[i], i));
        V<int> vsz;
        int pos = n * 2;
        while (pos > 0) {
            auto p = maxi[pos];
            vsz.pb(pos - p.se);
            pos = p.se;
        }
        debug(vsz);

        rep(i, n + 10) dp[i] = false;
        dp[0] = true;
        for (int v : vsz) {
            for (int j = n; j >= 0; --j) {
                if (j + v <= n) {
                    dp[j + v] |= dp[j];
                }
            }
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}