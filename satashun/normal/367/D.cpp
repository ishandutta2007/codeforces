//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ull = uint64_t;
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

    int n, m, d;
    cin >> n >> m >> d;
    V<int> wh(n);

    rep(i, m) {
        int s;
        cin >> s;
        rep(j, s) {
            int x;
            cin >> x;
            --x;
            wh[x] = i;
        }
    }

    V<int> cnt(m);
    rep(i, d) cnt[wh[i]]++;

    V<int> ng(1 << m);

    rep(i, n - d + 1) {
        int mask = 0;
        rep(j, m) if (cnt[j] > 0) { mask |= 1 << j; }
        ng[mask] = 1;

        if (i + d < n) {
            cnt[wh[i + d]]++;
        }
        cnt[wh[i]]--;
    }

    int ans = m;
    rep(i, m) {
        rep(j, 1 << m) {
            if (!(j >> i & 1)) {
                ng[j | (1 << i)] |= ng[j];
            }
        }
    }
    rep(i, 1 << m) {
        if (!ng[i]) {
            chmin(ans, m - __builtin_popcount(i));
        }
    }
    cout << ans << endl;

    return 0;
}