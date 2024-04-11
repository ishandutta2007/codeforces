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

    string s;
    cin >> s;

    if (s.length() == 1) {
        cout << s[0] << "\n";
        return 0;
    }

    s = "+" + s;

    pair <long long, long long> S[s.length() / 2 + 1];

    S[s.length() / 2] = {0, 0};
    for (int i = (int)s.length() - 2, j = (int)s.length() / 2 - 1; i >= 0; i -= 2, --j) {
        if (s[i] == '+') {
            S[j] = {0, S[j + 1].y};
            if (S[j + 1].x != 0) {
                S[j].y += S[j + 1].x * (s[i + 1] - '0');
            } else {
                S[j].y += S[j + 1].x + (s[i + 1] - '0');
            }
        } else {
            S[j] = {0, S[j + 1].y};
            if (S[j + 1].x != 0) {
                S[j].x += S[j + 1].x * (s[i + 1] - '0');
            } else {
                S[j].x += S[j + 1].x + (s[i + 1] - '0');
            }
        }
        //cout << i << " " << S[j].x << " " << S[j].y << "\n";
    }

    long long ans = LONG_MIN;

    pair <long long, long long> cur = {0, 0};

    for (int i = 0, j = 0; i < s.length(); i += 2, j++) {
        char last = '+';
        long long A = 0, B = 0;
        //cout << "CUR " << cur.x << " " << cur.y << "\n";
        for (int k = i + 1, l = j + 1; k < (int)s.length(); k += 2, l++) {
            if (last == '+') {
                B = A + B;
                A = s[k] - '0';
            } else {
                A *= (s[k] - '0');
            }
            //cout << i << " " << k << " " << A << " " << B << "\n";
            assert(l <= s.length() / 2);
            pair <long long, long long > R = S[l];

            long long res = cur.y + R.y;

            long long p = A + B;

            if (s[i] == '*') {
                p *= cur.x;
            } else {
                res += cur.x;
            }

            if (R.x != 0) {
                p *= R.x;
            }

            ans = max(ans, res + p);

            if (k + 1 < (int)s.length()) {
                last = s[k + 1];
            }
        }
        if (s[i] == '+') {
            cur.y += cur.x;
            cur.x = s[i + 1] - '0';
        } else {
            cur.x *= s[i + 1] - '0';
        }
    }

    cout << ans << "\n";


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}