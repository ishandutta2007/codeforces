#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

typedef int itn;

#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}


template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ld PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

void myassert(bool v) {
    assert(v);
    //cout << "FAIL\n";
    //exit(0);
}

mt19937 generator;

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

long long inv(long long a, long long p) {
    long long res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}

typedef vector <long long> vll;


template <class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

struct data {
    int cnt;
    ll sum;

    data() {
        cnt = INT_MAX / 2;
        sum = 0;
    }

    data(int c, ll s) {
        cnt = c;
        sum = s;
    }

    data operator+(const ll &x) const {
        return data(cnt + 1, sum + x);
    }

    bool operator<(const data &r) const {
        if (cnt != r.cnt) {
            return cnt < r.cnt;
        }
        return sum < r.sum;
    }
};


data dp[1001][6800];
pii pp[1001][6800];

void solve(int test) {
    int n = nxt();

    ll k = nxt<ll>();

    vll a(n);
    vll b(n);

    forn(i, n) {
        a[i] = nxt<ll>();
        b[i] = gcd(a[i], k);
//        a[i] = gcd(a[i], k);
    }

    if (k == 1) {
        cout << "1\n";
        cout << min_element(all(a)) - a.begin() + 1 << "\n";
        return;
    }



    vll divs;
    for (ll i = 1; i * i <= k; ++i) {
        if (k % i == 0) {
            divs.pb(i);
            if (i * i != k) divs.pb(k / i);
        }
    }

    sort(all(divs));

    cerr << divs.size() << endl;

//    for (auto x : divs) {
//        cerr << x << "\n";
//    }

    unordered_map<ll, int> ppp;

    for (int i = 0; i < divs.size(); ++i) {
        ppp[divs[i]] = i;
    }

    dp[0][0] = data{0, 0};

    cerr << clock() / 1.0 / CLOCKS_PER_SEC << endl;

    for (int i = 0; i < n; ++i) {
        auto * cur = dp[i + 1];
        auto * prev = dp[i];
        auto * P = pp[i + 1];
        for (int j = 0; j < divs.size(); ++j) {
//            if (divs[j] < b[j]) continue;
            cur[j] = prev[j];
            ll x = divs[j] / gcd(divs[j], b[i]);
            int p = ppp[x];
            if (uin(cur[j], prev[p] + a[i])) {
                P[j].x = 1;
                P[j].y = p;
            }
//            cerr << i << " " << divs[j] << " " << dp[i + 1][j].cnt << " " << dp[i + 1][j].sum << "\n";
        }
    }

    if (dp[n][divs.size() - 1].cnt > n) {
        cout << "-1\n";
    } else {
        int p = divs.size() - 1;
        vector <int> take;
        for (int i = n; i >= 1; --i) {
            if (pp[i][p].x) {
                take.pb(i);
                p = pp[i][p].y;
            }
        }
//        cerr << p << "\n";
//        assert(p == 0);
//        cerr << dp[n][divs.size() - 1].cnt << "\n";
//        cerr << take.size() << "\n";
        assert(take.size() == dp[n][divs.size() - 1].cnt);
        cout << take.size() << "\n";
        reverse(all(take));
        ll s = 0;
        for (int x : take) {
            s += a[x - 1];
        }
        assert(s == dp[n][divs.size() - 1].sum);
        for (int x : take) {
            cout << x << " ";
        }
        cout << "\n";
    }
}



int main(int argc, char **argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
//    pre();
//    test();
//    exit(0);
    int t = 1;

#ifdef LOCAL
#else
#endif
    int c = 0;

    while (t--) {
        solve(++c);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}