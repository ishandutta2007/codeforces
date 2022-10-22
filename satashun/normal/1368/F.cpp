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
void chmin(T &t, const U &u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T &t, const U &u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
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

int out(V<int> vec) {
    cout << SZ(vec);
    for (auto p : vec) cout << ' ' << p + 1;
    cout << endl;
    int x;
    cin >> x;
    --x;
    return x;
}

int main() {
    int n;
    cin >> n;

    int mx = -1000, mk = -1;

    for (int k = 1; k <= n; ++k) {
        int v = n - k - (n + k - 1) / k;
        if (mx < v) {
            mx = v;
            mk = k;
        }
    }

    V<bool> on(n);
    V<bool> sp(n);

    int ban = (n + mk - 1) / mk;
    rep(i, ban) sp[i * mk] = true;

    while (true) {
        V<int> pos;
        rep(i, n) if (!sp[i] && !on[i]) {
            pos.pb(i);
            if (SZ(pos) == mk) break;
        }
        if (SZ(pos) < mk) break;
        for (auto p : pos) on[p] = true;
        int x = out(pos);
        rep(i, mk) on[(x + i) % n] = false;
    }

    cout << 0 << endl;

    return 0;
}