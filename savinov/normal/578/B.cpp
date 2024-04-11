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

long long mod = 1000000007;

void fib(unsigned long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y += x;
        y %= mod;
    } else {
        long long a, b;
        fib(n / 2, a, b);
        x = (a * a + b * b) % mod;
        y = (2 * a + b) * b % mod;
    }
}

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int K, X;

long long minNum;

long long P[20];

vector <long long> cand;

void rec(int pos, long long x) {
    if (P[K - pos] * x < minNum) return;
    if (pos == K) {
        cand.push_back(x);
        return;
    }
    for (int i = 2; i <= X; ++i) {
        rec(pos + 1, x * i);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif



    int n = nxt();
    int k = nxt();
    long long x = nxt();

    K = k, X = x;

    P[0] = 1;

    for (int i = 1; i <= 15; ++i) {
        P[i] = x * P[i - 1];
    }

    long long mul = 1;
    for (int i = 0; i < k; ++i) {
        mul *= x;
    }

    long long ORP[n + 1];
    long long ORS[n + 1];

    clr(ORP);
    clr(ORS);

    long long a[n];
    int len[n];

    int maxLen = 0;

    long long q = 0;

    long long mu = 0;

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
        len[i] = 0;
        long long z = a[i];
        while (z) {
            len[i]++;
            z >>= 1;
        }
        q = max(q, a[i] * mul);
        mu = max(mu, a[i]);
        maxLen = max(maxLen, len[i]);
    }

    if (mu == 0) {
        cout << "0\n";
        return 0;
    }


    long long r = q >> maxLen;

    minNum = (((r << maxLen) + mu - 1) / mu);

    rec(0, 1);

//    cout << minNum << " " << mul << endl;
//
//    vector <long long> cand;
//
//    for (long long t = minNum; t <= mul; ++t) {
//
//    }

    for (int i = 0; i < n; ++i) {
        ORP[i + 1] = ORP[i] | a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        ORS[i] = ORS[i + 1] | a[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        //if (len[i] != maxLen) continue;
        //long long mi = ((r << maxLen) + a[i] - 1) / a[i];

        auto it = cand.begin();

        while (it != cand.end()) {
            ans = max(ans, (a[i] * *it) | ORP[i] | ORS[i + 1]);
            ++it;
        }
    }

    cout << ans << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}