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

// for factorize
const int MX = TEN(6) + 10;
int pr[MX];
V<int> vp;

void sieve() {
    memset(pr, -1, sizeof(pr));
    for (int i = 2; i < MX; ++i) {
        if (pr[i] == -1) {
            vp.pb(i);
            for (int j = i * 2; j < MX; j += i) {
                pr[j] = i;
            }
        }
    }
}

int prv(int x) {
    if (pr[x] == -1) return MX;
    int g = x;
    int mn = MX;
    while (pr[x] != -1) {
        int d = pr[x];
        while (x % d == 0) {
            x /= d;
        }
        chmin(mn, g - d + 1);
    }
    if (x != -1) {
        chmin(mn, g - pr[x] + 1);
    }
    return mn;
}

int main() {
    sieve();
    int X;
    cin >> X;
    int u = prv(X);
    dump(u);
    int ans = MX;
    for (int i = u; i <= X; ++i) {
        chmin(ans, prv(i));
    }
    cout << ans << endl;

    return 0;
}