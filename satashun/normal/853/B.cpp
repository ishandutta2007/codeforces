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

const ll INF = TEN(11);

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    V<pair<int, pair<int, pii>>> vs(m);
    rep(i, m) {
        int d, f, t, c;
        scanf("%d%d%d%d", &d, &f, &t, &c);
        --f;
        --t;
        int tp, to;
        if (f == -1) {
            tp = 1;
            to = t;
        } else {
            tp = 0;
            to = f;
        }
        vs[i] = mp(d, mp(tp, mp(to, c)));
    }
    sort(ALL(vs));

    V<multiset<int>> st(n);

    rep(i, m) {
        int tp = vs[i].se.fi;
        int to, c;
        tie(to, c) = vs[i].se.se;
        if (tp == 1) {
            st[to].insert(c);
        }
    }

    int now = 0;
    ll sum_in = INF * n;
    ll sum_out = 0;

    rep(i, n) {
        if (st[i].size() == 0) {
            puts("-1");
            return 0;
        }
        sum_out += *st[i].begin();
    }

    set<int> ind;
    ll ans = INF * n;
    V<ll> opt(n, INF);

    rep(i, m) {  // left
        int tp = vs[i].se.fi;
        int to, c;
        tie(to, c) = vs[i].se.se;
        debug(tp, to, c, vs[i].fi);
        if (tp == 0) {
            if (c < opt[to]) {
                sum_in = sum_in - opt[to] + c;
                ind.insert(to);
                opt[to] = c;
            }
        }
        if (ind.size() == n) {
            debug(i);
            while (now < m && vs[now].fi <= vs[i].fi + k) {  // erase
                int tp2 = vs[now].se.fi;
                if (tp2 == 1) {
                    int to2, c2;
                    tie(to2, c2) = vs[now].se.se;

                    sum_out -= *st[to2].begin();
                    st[to2].erase(st[to2].find(c2));
                    if (st[to2].size() == 0) {
                        if (ans == INF * n) {
                            ans = -1;
                        }
                        cout << ans << endl;
                        return 0;
                    }
                    sum_out += *st[to2].begin();
                }
                now++;
            }
            debug(sum_in, sum_out);

            chmin(ans, sum_in + sum_out);
        }
    }
    if (ans == INF * n) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}