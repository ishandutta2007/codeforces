#include "bits/stdc++.h"

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define itn int

#define next next12345
#define prev prev12345
#define x1 x12345
#define y1 y12345

using namespace std;

template <typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template <class _T> inline _T sqr(const _T& x) {return x * x;}
template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > PII;
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

template <typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

//typedef vector <vector <long long> > matrix;

char buf[1000000];


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "guard"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt(), m = nxt();

    long long h[n];

    long long m1 = 1000000007;
    long long m2 = m1 + 2;

    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        //puts(buf);
        int k = strlen(buf);
        long long h1 = 0, h2 = 0;
        for (int j = 0; j < k; ++j) {
            h1 = h1 * 5 + buf[j] - 'a' + 1;
            h2 = h2 * 5 + buf[j] - 'a' + 1;
            h1 %= m1;
            h2 %= m2;
        }
        //cout << h1 << " " << h2 << endl;
        h[i] = (h1 << 30ll) ^ h2;
    }
    sort(h, h + n);

//    long long p1[1000000], p2[1000000];
//    p1[0] = p2[0] = 1;
//    for (int i = 1; i < 1000000; ++i) {
//        p1[i] = p1[i - 1] * 5 % m1;
//        p2[i] = p2[i - 1] * 5 % m2;
//    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", buf);
        //puts(buf);
        int k = strlen(buf);
        long long h1 = 0, h2 = 0;
        for (int j = 0; j < k; ++j) {
            h1 = h1 * 5 + buf[j] - 'a' + 1;
            h2 = h2 * 5 + buf[j] - 'a' + 1;
            h1 %= m1;
            h2 %= m2;
        }
        //cout << h1 << " " << h2 << endl;
        long long p1 = 1, p2 = 1;
        for (int j = k - 1; j >= 0; --j) {
            for (int l = 'a'; l <= 'c'; ++l) {
                if (buf[j] == l) continue;
                long long hh1 = h1 + (l - buf[j] + m1) * p1;
                long long hh2 = h2 + (l - buf[j] + m2) * p2;
                hh1 %= m1;
                hh2 %= m2;
                //cout << j << " " << (char)(l) << " " << hh1 << " " << hh2 << " " << p1 << " " << p2 << endl;
                long long hf = (hh1 << 30ll) ^ hh2;
                if (binary_search(h, h + n, hf)) {
                    puts("YES");
                    goto l1;
                }
            }
            p1 = p1 * 5 % m1;
            p2 = p2 * 5 % m2;
        }

        puts("NO");

        l1:;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}