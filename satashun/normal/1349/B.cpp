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
    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        V<int> a(n);
        rep(i, n) cin >> a[i];
        bool isk = 0;
        bool ok = (n == 1);
        V<int> vec, big;
        rep(i, n) {
            if (a[i] == k) {
                vec.pb(i);
                isk = 1;

                for (int d = -2; d <= 2; ++d) {
                    if (d != 0 && i + d >= 0 && i + d < n) {
                        if (a[i + d] >= k) {
                            ok = 1;
                        }
                    }
                }
            } else if (a[i] > k) {
                big.pb(i);
            }
        }
        if (!isk) {
            puts("no");
            continue;
        }
        if (ok) {
            puts("yes");
            continue;
        }
        {
            int sz = vec.size();
            rep(i, sz - 1) {
                if (vec[i + 1] - vec[i] == 2) {
                    ok = 1;
                }
            }
        }

        {
            int sz = big.size();
            rep(i, sz - 1) {
                if (big[i + 1] - big[i] <= 2) {
                    ok = 1;
                }
            }
        }

        puts(ok ? "yes" : "no");
    }
    return 0;
}