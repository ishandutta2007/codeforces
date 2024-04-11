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

const int L = TEN(6);

void out(const V<int>& vec) {
    int sz = vec.size();
    cout << sz << endl;
    rep(i, sz) { cout << vec[i] + 1 << (i == sz - 1 ? '\n' : ' '); }
    exit(0);
}

int main() {
    int n;
    cin >> n;
    V<pii> vec;

    rep(i, n) {
        int x, y;
        cin >> x >> y;
        vec.eb(x, y);
    }

    for (auto& p : vec) {
        p.fi += L;
        p.se += L;
    }

    while (true) {
        debug(vec);
        V<int> gr[2][2];

        rep(i, n) {
            auto p = vec[i];
            gr[p.fi % 2][p.se % 2].pb(i);
        }

        bool t = false;
        rep(i, 2) {
            rep(j, 2) {
                if (gr[i][j].size() == n) {
                    t = true;
                }
            }
        }
        if (t) {
            for (auto& p : vec) {
                p.fi /= 2;
                p.se /= 2;
            }
            continue;
        }
        if (gr[0][0].size() + gr[1][1].size() == 0) {
            V<int> ans;
            for (int p : gr[0][1]) {
                ans.pb(p);
            }
            out(ans);
        } else if (gr[0][1].size() + gr[1][0].size() == 0) {
            V<int> ans;
            for (int p : gr[0][0]) {
                ans.pb(p);
            }
            out(ans);
        } else {
            V<int> ans;
            for (int p : gr[0][0]) {
                ans.pb(p);
            }
            for (int p : gr[1][1]) {
                ans.pb(p);
            }
            out(ans);
        }
    }

    return 0;
}