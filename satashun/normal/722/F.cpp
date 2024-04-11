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

const int maxk = 41;

int main() {
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    VV<pii> occ(m);
    V<int> k(n);

    rep(i, n) {
        cin >> k[i];
        rep(j, k[i]) {
            int a;
            cin >> a;
            --a;
            occ[a].eb(i, j);
        }
    }

    auto tf = [&](V<pii>& vec) {
        for (auto& p : vec) {
            p.fi = k[p.fi];
        }
    };

    rep(a, m) {
        debug(a, occ[a]);
        VV<pii> rng;
        V<pii> cur;

        for (auto p : occ[a]) {
            if (cur.size() && cur.back().fi == p.fi - 1) {
                cur.eb(p);
            } else {
                if (cur.size()) {
                    tf(cur);
                    rng.eb(cur);
                }
                cur.clear();
                cur.pb(p);
            }
        }

        tf(cur);
        rng.eb(cur);
        debug(rng);

        int ans = 0;
        V<int> pos(maxk, -1);
        V<int> cnt(maxk);

        auto add = [&](int len, int p) {
            if (pos[len] != -1) {
                return pos[len] == p;
            }
            bool ok = 1;
            pos[len] = p;
            for (int i = 1; i <= 40; ++i) {
                if (pos[i] != -1) {
                    int d = __gcd(i, len);
                    if (pos[i] % d != p % d) {
                        ok = 0;
                    }
                }
            }
            pos[len] = -1;
            return ok;
        };

        for (auto vec : rng) {
            int l = 0, r = 0;
            for (int l = 0; l < vec.size(); ++l) {
                while (r < vec.size() && add(vec[r].fi, vec[r].se)) {
                    pos[vec[r].fi] = vec[r].se;
                    cnt[vec[r].fi]++;
                    r++;
                }
                chmax(ans, r - l);
                if (--cnt[vec[l].fi] == 0) {
                    pos[vec[l].fi] = -1;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}