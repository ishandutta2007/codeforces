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

void slv() {
    int n;
    cin >> n;
    V<int> a(n);
    rep(i, n) {
        cin >> a[i];
        --a[i];
    }
    rep(i, n) {
        if (a[i] % 2 != i % 2) {
            cout << -1 << '\n';
            return;
        }
    }

    V<int> ope;

    auto add = [&](int p) {
        p++;
        ope.pb(p);
        reverse(a.begin(), a.begin() + p);
        debug(a);
    };

    for (int i = n - 1; i > 0; i -= 2) {
        if (a[i] == i && a[i - 1] == i - 1) continue;
        rep(j, i + 1) {
            if (a[j] == i) {
                add(j);
                break;
            }
        }
        rep(j, i + 1) {
            if (a[j] == i - 1) {
                add(j - 1);
                add(j + 1);
                break;
            }
        }

        add(2);
        add(i);
    }

    int k = SZ(ope);
    debug(k);
    cout << k << '\n';
    rep(i, k) { cout << ope[i] << (i == k - 1 ? '\n' : ' '); }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        slv();
    }
    return 0;
}