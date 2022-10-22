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
    int n;
    cin >> n;
    int N = n * 2;
    if (n % 2 == 0) {
        cout << "First" << endl;
        rep(i, N) { cout << i % n + 1 << (i == N - 1 ? '\n' : ' '); }
        fflush(stdout);
    } else {
        cout << "Second" << endl;
        V<int> a(N);
        VV<int> pr(N);
        rep(i, N) {
            cin >> a[i];
            --a[i];
            pr[a[i]].pb(i);
        }
        V<bool> vis(n);
        V<int> ans(n, -1);
        rep(i, n) {
            if (vis[i]) continue;
            int x = pr[i][0], id = i, j = 0;
            while (!vis[id]) {
                vis[id] = true;
                ans[id] = x;
                int nx = pr[id][j ^ 1];
                if (nx < n)
                    nx += n;
                else
                    nx -= n;
                int nj;
                int nid = a[nx];
                rep(k, 2) if (pr[nid][k] == nx) { nj = k; }
                x = nx;
                id = nid;
                j = nj;
            }
        }
        ll s = 0;
        rep(i, n) s += ans[i] + 1;
        if (s % N != 0) {
            rep(i, n) {
                rep(j, 2) if (pr[i][j] != ans[i]) {
                    ans[i] = pr[i][j];
                    break;
                }
            }
        }
        rep(i, n) cout << ans[i] + 1 << (i == n - 1 ? '\n' : ' ');
    }
    return 0;
}