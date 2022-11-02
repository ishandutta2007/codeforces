#include "bits/stdc++.h"

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

random_device device;
mt19937 generator(device());

unsigned int nextRandom() {
    return generator();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

inline string next() {
    static int c;
    string res;
    while (isspace(c = getchar())) {}
    while (!isspace(c)) {
        res = res + (char)c;
        c = getchar();
    }
    return res;
}


long long pw(long long a, long long n, long long mod) {
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


vector <int> getZ(string s) {
    int l = -1, r = -1;
    vector <int> z(s.length());


    for (int i = 1; i < s.length(); ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < s.length() && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (r < i + z[i]) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif


    int n = nxt();
    int m = nxt();

    string s;
    cin >> s;

    int pos[m];

    for (int x = 0; x < m; ++x) {
        pos[x] = nxt() - 1;
    }

    vector <int> z = getZ(s);

    int free = m ? pos[0] + n - pos[m - 1] - (int)s.length() : n;

    for (int x = 0; x + 1 < m; ++x) {
        int v = pos[x + 1] - pos[x];
        if (v < s.length()) {
            if (z[v] + v != s.length()) {
                cout << "0\n";
                exit(0);
            }
        } else {
            free += v - s.length();
        }
    }
    long long ans = 1;
    long long mod = 1000000007;
    for (int i = 0; i < free; ++i) {
        ans = ans * 26 % mod;
    }

    cout << ans << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}