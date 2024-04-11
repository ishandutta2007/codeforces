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

const int maxn = 5010;
V<int> g[maxn];
int p[maxn];
int lf[maxn];

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    --a, --b, --c, --d;

    p[0] = -1;
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        g[p[i]].pb(i);
    }

    for (int i = n - 1; i > 0; --i) {
        if (g[i].size() == 0) {
            lf[i] = 1;
        }
        lf[p[i]] += lf[i];
    }

    if (lf[0] % 2 != 0) {
        puts("NO");
        return 0;
    }

    auto enum_sz = [&](int v) {
        V<int> res;
        while (v) {
            int pp = p[v];
            if (pp == 0) {
                break;
            }
            for (int to : g[pp]) {
                if (to != v) {
                    res.pb(lf[to]);
                }
            }
            v = pp;
        }
        return res;
    };

    auto get = [&](int v) {
        while (p[v] != 0) {
            v = p[v];
        }
        return v;
    };

    int num = lf[0] / 2;

    auto check = [&](int p, int q, int r) {  // p->q, skip r
        auto v1 = enum_sz(p);
        auto v2 = enum_sz(q);
        int rp = get(p), rq = get(q), rr = get(r);
        V<int> vec;

        vec.insert(vec.end(), ALL(v1));
        vec.insert(vec.end(), ALL(v2));

        for (int to : g[0]) {
            if (to != rp && to != rq && to != rr) {
                vec.pb(lf[to]);
            }
        }

        V<bool> dp(n + 1);
        dp[0] = true;
        for (int v : vec) {
            for (int j = n; j >= v; --j) {
                if (dp[j - v]) {
                    dp[j] = true;
                }
            }
        }
        debug(p, q, r);
        debug(num, num - 1 - lf[rr], dp[num - 1 - lf[rr]]);
        return num - 1 >= lf[rr] && dp[num - 1 - lf[rr]];
    };

    if (check(a, b, c) && check(c, d, b)) {
        puts("YES");
    } else if (check(a, b, d) && check(c, d, b)) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}