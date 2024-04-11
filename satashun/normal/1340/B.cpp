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

const string digits[10] = {"1110111", "0010010", "1011101", "1011011",
                           "0111010", "1101011", "1101111", "1010010",
                           "1111111", "1111011"};

const int maxn = 2010;

int dig_mask[10];
int mx[maxn][8];

bool dp[maxn][maxn];

int main() {
    rep(i, 10) {
        rep(j, 7) if (digits[i][j] == '1') { dig_mask[i] |= (1 << j); }
    }

    memset(mx, -1, sizeof(mx));

    int n, k;
    cin >> n >> k;
    rep(i, n) {
        string s;
        cin >> s;
        int cur = 0;
        rep(j, 7) if (s[j] == '1') { cur |= (1 << j); }

        rep(d, 10) {
            int m = dig_mask[d];
            if ((m & cur) == cur) {
                int on = __builtin_popcount(m ^ cur);
                chmax(mx[i][on], d);
            }
        }
    }

    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j)
            if (dp[i + 1][j]) {
                for (int num = 0; num <= 7 && j + num <= k; ++num) {
                    if (mx[i][num] != -1) {
                        dp[i][j + num] = true;
                    }
                }
            }
    }

    if (!dp[0][k]) {
        puts("-1");
        return 0;
    }

    int rem = k;
    string ans(n, '?');

    rep(i, n) {
        int nx = -1, pnum = -1;
        for (int num = 0; num <= 7; ++num) {
            if (mx[i][num] != -1 && rem >= num && dp[i + 1][rem - num]) {
                if (nx < mx[i][num]) {
                    nx = mx[i][num];
                    pnum = num;
                }
            }
        }
        rem -= pnum;
        ans[i] = '0' + nx;
    }
    cout << ans << endl;

    return 0;
}