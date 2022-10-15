#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const ll MOD = 1'000'000'007;
const int MAXN = 5017, ALP = 27;
ll dp[MAXN][ALP];

ll bp(ll a, ll pw) { 
    ll res(1);
    for (; pw; a = sqr(a) % MOD, pw /= 2) 
        if (pw & 1) 
            res = (res * a) % MOD;
    return res;
}
ll reverse(ll a) {return bp(a, MOD - 2); }

const int MAXC = 1e5 + 15;

ll f[MAXC], rev[MAXC];

struct prepare{
    prepare() {
        f[0] = 1;
        for (int i = 1; i < MAXC; ++i) f[i] = (f[i - 1] * i) % MOD;
        rev[MAXC - 1] = reverse(f[MAXC - 1]);
        for (int i = MAXC - 2; i >= 0; --i) rev[i] = (rev[i + 1] * (i + 1)) % MOD;
    }
} prepare;

ll C(ll n, ll k) {
    if (k > n) return 0;
    return (((f[n] * rev[k]) % MOD) * rev[n - k]) % MOD;
}

int main() {

    int n;
    string s;
    cin >> n >> s;

    dp[0][ALP - 1] = 1;

    for (int i = 0; i < n; ++i) {
        // int cur  =   i & 1;
        // int next = cur ^ 1;
        int sym = s[i] - 'a';

        for (int j = i + 1; j >= 1; --j) {
            dp[j][sym] = 0;
            for (int c = 0; c < ALP; ++c)
                if (sym != c) 
                    dp[j][sym] += dp[j - 1][c];
            dp[j][sym] %= MOD;
        }
    }

    ll ans = 0;
    for (int j = 1; j <= n; ++j) {
        ll cur = 0;
        for (int c = 0; c < ALP; ++c)
            cur += dp[j][c];
        cur %= MOD;
        cur *= C(n - 1, j - 1);
        cur %= MOD;
        ans += cur;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}