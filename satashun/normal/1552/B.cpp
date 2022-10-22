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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        auto v = make_vec<int>(n, 5);
        rep(i, n) { rep(j, 5) cin >> v[i][j]; }

        V<int> lose(n);
        rep(i, 5) {
            rep(j, i) {
                rep(k, j) {
                    V<pair<V<int>, int>> vec;
                    rep(p, n) {
                        V<int> u{v[p][k], v[p][j], v[p][i]};
                        vec.eb(u, p);
                    }
                    sort(ALL(vec));
                    // reverse(ALL(vec));

                    set<pair<pii, int>> st;
                    // debug(vec);

                    for (auto& [v, p] : vec) {
                        int a = v[0], b = v[1], c = v[2];
                        auto it = st.lower_bound(mp(mp(b + 1, -1e9), -1e9));
                        if (it != st.begin()) {
                            auto itl = it;
                            itl--;
                            if (itl->fi.se <= c) {
                                lose[p] = 1;
                                continue;
                            }
                        }

                        while (it != st.end()) {
                            if (it->fi.se >= c) {
                                it = st.erase(it);
                            } else {
                                break;
                            }
                        }
                        st.insert(mp(mp(b, c), p));
                    }
                }
            }
        }
        debug(lose);
        int p = -1;
        rep(i, n) {
            if (!lose[i]) {
                p = i;
            }
        }
        if (p != -1) p++;
        cout << p << '\n';
    }
    return 0;
}