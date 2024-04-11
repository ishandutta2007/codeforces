#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
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
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

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

mt19937 generator;

const int N = 500000 + 1;

int lp[N];

int dp[N];

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            for (int j = i; j <= N; j += i) {
                lp[j] = i;
            }
        }
    }

    int n = nxt(), q = nxt();

    vector <int> divisors[n];
    vector <int> mu[n];

    for (int i = 0; i < n; ++i) {
        int x = nxt();
        vector <int> primes;
        while (x > 1) {
            int l = lp[x];
            while (lp[x] == l) {
                x /= l;
            }
            primes.push_back(l);
        }
//        for (int x : primes) {
//            cout << x << " ";
//        }
        //cout << "\n";
        for (int mask = 0; mask < (1 << primes.size()); ++mask) {
            int cur = 1;
            int z = 1;
            for (int j = 0; j < primes.size(); ++j) {
                if (mask & (1 << j)) {
                    cur *= primes[j];
                    z *= -1;
                }
            }
            divisors[i].push_back(cur);
            mu[i].push_back(z);
        }
    }

    long long ans = 0;
    char used[n];
    clr(used);

    int cnt = 0;

    for (int i = 0; i < q; ++i) {
        int v = nxt() - 1;
        if (used[v]) {
            for (int j = 0; j < (int)divisors[v].size(); ++j) {
                dp[divisors[v][j]]--;
            }
            for (int j = 0; j < (int)divisors[v].size(); ++j) {
                ans -= mu[v][j] * dp[divisors[v][j]];
            }
            used[v] = 0;
        } else {
            for (int j = 0; j < (int)divisors[v].size(); ++j) {
                ans += mu[v][j] * dp[divisors[v][j]];
            }
            for (int j = 0; j < (int)divisors[v].size(); ++j) {
                dp[divisors[v][j]]++;
            }
            used[v] = 1;
            ++cnt;
        }
        cout << ans << "\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}