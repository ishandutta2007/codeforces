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

const int maxn = 22;
int u[maxn];
int adj[1 << maxn];
bool con[1 << maxn];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        u[a] |= 1 << b;
        u[b] |= 1 << a;
    }

    if (m == n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    rep(i, n) {
        con[1 << i] = true;
        adj[1 << i] = u[i] | (1 << i);
    }

    rep(i, 1 << n) {
        rep(j, n) {
            if ((i >> j) & 1) {
                adj[i] |= u[j];
            }
        }
        rep(j, n) if (adj[i] >> j & 1) { con[i] |= con[i ^ (1 << j)]; }
    }

    rep(i, 1 << n) { debug(i, adj[i]); }

    int mini = n + 1, mask = -1;
    rep(i, 1 << n) {
        if (adj[i] == (1 << n) - 1 && con[i]) {
            int s = __builtin_popcount(i);
            debug(i, s);
            if (mini > s) {
                mini = s;
                mask = i;
            }
        }
    }

    cout << mini << endl;
    int c = 0;
    rep(i, n) {
        if (mask >> i & 1) {
            ++c;
            cout << i + 1 << (c == mini ? '\n' : ' ');
        }
    }

    return 0;
}