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

int ask(int i, int j) {
    printf("? %d %d\n", i, j);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int n;

void answer(int num, V<int> p) {
    printf("!\n");
    printf("%d\n", num);
    rep(i, n) { printf("%d%c", p[i], i == n - 1 ? '\n' : ' '); }
    fflush(stdout);
}

const int maxn = 5010;
int xo[maxn][maxn];

int main() {
    cin >> n;
    rep(i, n) { xo[0][i] = ask(0, i); }

    for (int i = 1; i < n; ++i) {
        xo[i][0] = ask(i, 0);
    }

    int ans = 0;
    V<int> ap;

    rep(x, n) {
        V<int> p(n), q(n);
        p[0] = x;

        rep(i, n) { q[i] = xo[0][i] ^ x; }

        rep(i, n) { p[i] = xo[i][0] ^ q[0]; }

        bool ok = 1;
        rep(i, n) {
            if (p[i] >= n || q[i] >= n) {
                ok = 0;
            }
        }
        if (ok) {
            rep(i, n) {
                if (p[q[i]] != i) {
                    ok = 0;
                }
            }
        }
        if (ok) {
            ans++;
            ap = p;
        }
    }

    answer(ans, ap);

    return 0;
}