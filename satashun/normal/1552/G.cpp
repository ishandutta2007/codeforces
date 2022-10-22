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

const string OK = "ACCEPTED\n";
const string NG = "REJECTED\n";

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << OK;
        return 0;
    }

    VV<int> v(k);
    V<int> use(n);
    rep(i, k) {
        int q;
        cin >> q;
        rep(j, q) {
            int x;
            cin >> x;
            --x;
            v[i].pb(x);
            use[x] = 1;
        }
    }
    rep(i, n) if (!use[i]) {
        cout << NG;
        return 0;
    }

    auto slv = [&](auto&& rec, int i, ll mask_fix, ll num) -> bool {
        if (i == k) {
            debug(mask_fix, num);
            int la = 0;
            rep(p, n) {
                int nx = num >> p & 1;
                if (la > nx) {
                    return false;
                }
                la = nx;
            }
            return true;
        }

        int cnt = SZ(v[i]);
        int c[2] = {0};
        V<int> vf;
        for (int x : v[i]) {
            if (mask_fix >> x & 1) {
                c[num >> x & 1]++;
            } else {
                vf.pb(x);
                mask_fix |= 1ll << x;
            }
        }

        ll rel = 0;
        for (int x : v[i]) {
            rel |= 1ll << x;
        }

        for (int nx0 = c[0]; nx0 <= cnt - c[1]; ++nx0) {
            ll nx_num = num | rel;
            rep(j, nx0) nx_num ^= 1ll << v[i][j];
            if (!rec(rec, i + 1, mask_fix, nx_num)) return false;
        }
        return true;
    };
    if (slv(slv, 0, 0, 0)) {
        cout << OK;
    } else {
        cout << NG;
    }

    return 0;
}