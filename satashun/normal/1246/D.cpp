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

const int maxn = 100010;
V<int> g[maxn];
int p[maxn];
int dep[maxn];

void dfs(int v, int d) {
    dep[v] = d;
    for (int to : g[v]) {
        dfs(to, d + 1);
    }
}

int main() {
    int n;
    cin >> n;
    p[0] = -1;
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        g[p[i]].pb(i);
    }
    dfs(0, 0);
    pii cand(-1, -1);
    rep(i, n) chmax(cand, mp(dep[i], i));

    debug(cand);

    V<int> ope;

    V<bool> used(n);
    queue<int> que;
    V<int> lo(n, -1);
    {
        int v = cand.se;
        while (v != -1) {
            for (int to : g[v]) {
                if (!used[to]) {
                    que.push(to);
                }
            }
            if (p[v] != -1) {
                lo[p[v]] = v;
            }
            used[v] = true;
            v = p[v];
        }
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        used[v] = true;
        int par = p[v];
        int ch = lo[par];
        ope.pb(ch);
        p[ch] = v;
        lo[par] = v;
        lo[v] = ch;
        for (int to : g[v]) {
            if (!used[to]) {
                que.push(to);
            }
        }
    }

    int v = 0;
    rep(i, n) {
        printf("%d%c", v, i == n - 1 ? '\n' : ' ');
        v = lo[v];
    }

    reverse(ALL(ope));
    int sz = ope.size();
    printf("%d\n", sz);
    rep(i, sz) { printf("%d%c", ope[i], i == sz - 1 ? '\n' : ' '); }
    return 0;
}