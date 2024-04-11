#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 300005
#define MAXM 25

const int MOD = 998244353;

long long fact[MAXN], inv[MAXN];

long long sub(long long a, long long b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

long long inverse(long long a) {
    long long ret = 1;
    for (int b=MOD-2; b>0; b/=2) {
        if (b % 2) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

long long choose(int n, int k) {
    if (n < 0 || k < 0 || n < k)
        return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int cnt[MAXN], l[MAXN], r[MAXN], a[MAXM], b[MAXM], has[MAXN];
long long pref[MAXN][2*MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
        cnt[l[i]]++;
        cnt[r[i]+1]--;
    }
    for (int i=0; i<m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    fact[0] = inv[0] = 1;
    for (int i=1; i<=n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = inverse(fact[i]);
        cnt[i] += cnt[i-1];
    }

    for (int i=1; i<=n; i++)
        for (int j=0; j<=2*m; j++) {
            pref[i][j] = pref[i-1][j] + choose(cnt[i] - j, i - j);
            if (pref[i][j] >= MOD)
                pref[i][j] -= MOD;
        }

    long long ret = 0;
    for (int mask=0; mask<1<<m; mask++) {
        int curL = 1, curR = n, k = 0, sign = 1;
        for (int i=0; i<m; i++)
            if (mask & (1 << i)) {
                if (has[a[i]] != mask + 1) {
                    has[a[i]] = mask + 1;
                    k++;
                }
                if (has[b[i]] != mask + 1) {
                    has[b[i]] = mask + 1;
                    k++;
                }
                curL = max({curL, l[a[i]], l[b[i]]});
                curR = min({curR, r[a[i]], r[b[i]]});
                sign *= -1;
            }
        if (curL <= curR) {
            ret += sign * sub(pref[curR][k], pref[curL-1][k]);
            if (ret >= MOD)
                ret -= MOD;
            if (ret < 0)
                ret += MOD;
        }
    }
    cout << ret << "\n";

    return 0;
}