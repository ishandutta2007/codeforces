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

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        V<int> p(n), pos(n);
        V<int> cnt(n, 1);
        set<pii> st;
        rep(i, n) { st.insert(mp(1, i)); }

        rep(i, n) {
            scanf("%d", &p[i]);
            --p[i];
            pos[p[i]] = i;
        }
        set<int> alive;
        rep(i, n) alive.insert(i);
        bool ok = 1;

        rep(i, n) {
            auto it = *st.rbegin();
            int mx = it.fi;
            int val = cnt[pos[i]];
            // debug(i, mx, val);
            if (mx != val) {
                ok = 0;
                break;
            }
            auto itr = alive.upper_bound(pos[i]);
            st.erase(mp(cnt[pos[i]], pos[i]));
            alive.erase(pos[i]);

            if (itr != alive.end()) {
                int nx = *itr;
                // debug(i, pos[i], nx);
                st.erase(mp(cnt[nx], nx));
                cnt[nx] += cnt[pos[i]];
                st.insert(mp(cnt[nx], nx));
            }
        }
        puts(ok ? "Yes" : "No");
    }
    return 0;
}