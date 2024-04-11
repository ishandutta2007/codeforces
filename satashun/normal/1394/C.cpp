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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    V<pii> vec;

    rep(i, n) {
        string s;
        cin >> s;
        int c1 = 0, c2 = 0;
        for (auto c : s) {
            if (c == 'B')
                c1++;
            else
                c2++;
        }
        vec.eb(c1, c2);
    }
    debug(vec);

    constexpr int INF = TEN(9);

    pii ans;

    auto ok = [&](int d) {
        int mx = 0, Mx = INF, my = 0, My = INF, mxy = -INF, Mxy = INF;
        for (auto p : vec) {
            int x, y;
            tie(x, y) = p;
            chmax(mx, x - d);
            chmin(Mx, x + d);
            chmax(my, y - d);
            chmin(My, y + d);
            chmax(mxy, x - y - d);
            chmin(Mxy, x - y + d);
        }
        if (!(mx <= Mx && my <= My && mxy <= Mxy)) return false;

        for (int i = max(0, mx); i <= Mx; ++i) {
            int l = max(0, i - Mxy), r = i - mxy;
            if (l > r) continue;

            pii a(l, r), b(my, My);
            if (a > b) swap(a, b);
            if (min(a.se, b.se) >= b.fi && i + min(a.se, b.se) > 0) {
                ans = mp(i, min(a.se, b.se));
                return true;
            }
        }

        return false;
    };

    int lo = 0, hi = TEN(6) * 2;
    if (ok(0)) hi = 0;
    while (hi - lo > 1) {
        int m = (lo + hi) / 2;
        if (ok(m))
            hi = m;
        else
            lo = m;
    }
    cout << hi << endl;
    ok(hi);
    string t = string(ans.fi, 'B') + string(ans.se, 'N');
    cout << t << endl;

    return 0;
}