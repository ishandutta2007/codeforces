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

const int INF = TEN(9);
const int maxn = 200010;

const string cand[4] = {"RL", "RRL", "RLL", "RRLL"};

int dp[maxn];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int TC;
    cin >> TC;

    while (TC--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = n;

        rep(i, 4) {
            if (i == n) break;
            string t = s;
            rotate(t.begin(), t.begin() + i, t.end());
            // debug(t);
            fill(dp, dp + n + 1, INF);
            dp[0] = 0;

            rep(j, n) {
                rep(k, 4) {
                    auto& c = cand[k];
                    if (j + c.size() > n) continue;
                    int sc = dp[j];
                    rep(l, c.size()) {
                        if (c[l] != t[j + l]) sc++;
                    }
                    chmin(dp[j + c.size()], sc);
                }
            }
            //  debug(i, dp[n]);
            chmin(ans, dp[n]);
        }

        cout << ans << endl;
    }
    return 0;
}