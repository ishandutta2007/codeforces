#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

//#define next next12345
//#define prev prev12345
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
typedef pair<int, int> PII;
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


void read() {
    int n = nxt();

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }

    sort(a, a + n);

    const int K = 5001;

    int pos[K + 2];
    int neg[K + 2];
    clr(pos);
    clr(neg);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (a[i] > a[j])
                pos[a[i] - a[j]] += 1;
            else
                neg[a[j] - a[i]] += 1;
        }
    }

    long long tmp[3 * K + 2];
    clr(tmp);
    long long * dp = tmp + K;
    dp[0] = 1;

    for (int i = 0; i < 2; ++i) {
        long long q[3 * K + 2];
        clr(q);
        long long * v = q + K;

        for (int j = 0; j <= 2 * K; ++j) {
            for (int z = 0; z <= K; ++z) {
                if (pos[z] && dp[j])
                    v[z + j] += dp[j] * pos[z];
            }
        }
        memcpy(tmp, q, sizeof(tmp));
    }

    long long q[3 * K + 2];
    clr(q);
    long long * v = q + K;

    for (int j = 0; j <= 2 * K; ++j) {
        for (int z = 0; z <= K; ++z) {
            if (neg[z] && dp[j])
                v[j - z] += dp[j] * neg[z];
        }
    }
    long long s = 0;
    for (int i = -K; i < 0; ++i) {
        s += v[i];
    }
    long double z = n * (n - 1) / 2;
    //cerr << 3 * log10(2000 * 1000) << endl;
    cerr << logl(pow(2000 * 1000, 3)) << endl;
    cerr << logl(LLONG_MAX) << endl;
    cout << setprecision(10) << fixed;
    cerr << s << endl;
    cout << s / z / z / z << endl;


}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sociology"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
//    pre();
#ifdef LOCAL
#endif

//    test();
//    solve2();

//    gen();

    int c = 0;
    while (t--) {
        //gen();
        read();
//        gen();
//        gen2();

    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}