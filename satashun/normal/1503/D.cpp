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
    int n;
    cin >> n;
    V<int> rev(n);
    V<int> vec(n);
    bool ng = 0;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        bool r = a > b;
        if (r) {
            swap(a, b);
        }
        if (a >= n || b < n) {
            ng = 1;
            break;
        }
        rev[a] = r;
        vec[a] = b;
    }

    if (!ng) {
        V<int> vl{TEN(9)}, vr{TEN(9)};
        rep(i, n) {
            if (vl.back() < vr.back()) {
                if (vec[i] < vl.back()) {
                    vl.pb(vec[i]);
                } else if (vec[i] < vr.back()) {
                    vr.pb(vec[i]);
                } else {
                    ng = 1;
                    break;
                }
            } else {
                if (vec[i] < vr.back()) {
                    vr.pb(vec[i]);
                } else if (vec[i] < vl.back()) {
                    vl.pb(vec[i]);
                } else {
                    ng = 1;
                    break;
                }
            }
        }
    }
    if (ng) {
        cout << -1 << endl;
        return 0;
    }

    V<int> heads;
    {
        V<int> tor(n + 1);
        tor[n] = -1;
        per(i, n) tor[i] = max(tor[i + 1], vec[i]);
        int mini = TEN(9);
        rep(i, n) {
            if (mini > tor[i]) {
                heads.pb(i);
            }
            chmin(mini, vec[i]);
        }
        heads.pb(n);
    }
    int ans = 0;
    debug(heads);
    debug(vec);
    debug(rev);

    rep(p, SZ(heads) - 1) {
        V<int> vl{TEN(9)}, vr{TEN(9)};
        int ct = 0;

        for (int i = heads[p]; i < heads[p + 1]; ++i) {
            if (vl.back() < vr.back()) {
                if (vec[i] < vl.back()) {
                    if (!rev[i]) ct++;
                    vl.pb(vec[i]);
                } else if (vec[i] < vr.back()) {
                    if (rev[i]) ct++;
                    vr.pb(vec[i]);
                } else {
                    ng = 1;
                    break;
                }
            } else {
                if (vec[i] < vr.back()) {
                    if (rev[i]) ct++;
                    vr.pb(vec[i]);
                } else if (vec[i] < vl.back()) {
                    if (!rev[i]) ct++;
                    vl.pb(vec[i]);
                } else {
                    ng = 1;
                    break;
                }
            }
        }

        ans += min(ct, heads[p + 1] - heads[p] - ct);
    }
    cout << ans << endl;

    return 0;
}