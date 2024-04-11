//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

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

void out(V<int> v) {
    for (int x : v) {
        cout << char('a' + x);
    }
    cout << '\n';
}

void slv(string s) {
    int n = SZ(s);
    bool same = 1;
    rep(i, n) if (s[i] != s[0]) { same = 0; }
    if (same) {
        cout << s << '\n';
        return;
    }

    V<int> cnt(26);
    for (auto c : s) cnt[c - 'a']++;
    V<int> t;

    rep(i, 26) if (cnt[i] == 1) {
        t.pb(i);
        cnt[i]--;
        rep(c, 26) rep(k, cnt[c]) { t.pb(c); }
        out(t);
        return;
    }
    int p = 0;
    rep(i, 26) if (cnt[i] > 0) {
        p = i;
        break;
    }

    if (n - cnt[p] >= cnt[p] - 2) {
        rep(c, 2) t.pb(p);
        cnt[p] -= 2;
        bool f = 1;
        rep(i, n - 2) {
            if (f) {
                rep(c, 26) if (cnt[c] && c != p) {
                    t.pb(c);
                    --cnt[c];
                    f = 0;
                    break;
                }
            } else {
                if (cnt[p]) {
                    t.pb(p);
                    --cnt[p];
                    f = 1;
                } else {
                    rep(c, 26) if (cnt[c] && c != p) {
                        t.pb(c);
                        --cnt[c];
                        f = 0;
                        break;
                    }
                }
            }
        }
        out(t);
        return;
    }

    int q;
    rep(i, 26) if (cnt[i] && i != p) {
        q = i;
        break;
    }
    if (cnt[p] + cnt[q] < n) {
        t.pb(p);
        --cnt[p];
        t.pb(q);
        --cnt[q];

        rep(i, cnt[p]) t.pb(p);
        cnt[p] = 0;
        bool f = 1;

        while (SZ(t) < n) {
            rep(i, 26) {
                if (cnt[i] && (!f || i != q)) {
                    --cnt[i];
                    t.pb(i);
                    i--;
                    f = 0;
                    break;
                }
            }
        }
    } else {
        t.pb(p);
        rep(i, cnt[q]) t.pb(q);
        rep(i, cnt[p] - 1) t.pb(p);
    }
    out(t);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        slv(s);
    }
    return 0;
}