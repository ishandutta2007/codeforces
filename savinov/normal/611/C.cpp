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

template <class T>
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


int A[1000][1000];

int B[1000][1000];

int SA(int x1, int y1, int x2, int y2) {
    return A[x2][y2] - A[x1][y2] - A[x2][y1] + A[x1][y1];
};

int SB(int x1, int y1, int x2, int y2) {
    return B[x2][y2] - B[x1][y2] - B[x2][y1] + B[x1][y1];
};

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "ticket-office"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int h = nxt();
    int w = nxt();

    string s[h];

    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x = 0;
            if (i + 1 < h && s[i][j] == '.' && s[i + 1][j] == '.') {
                x += 1;
            }
            int y = 0;
            if (j + 1 < w && s[i][j] == '.' && s[i][j + 1] == '.') {
                y += 1;
            }
            A[i + 1][j + 1] = A[i + 1][j] + A[i][j + 1] - A[i][j] + x;
            B[i + 1][j + 1] = B[i + 1][j] + B[i][j + 1] - B[i][j] + y;

//            cerr << B[i + 1][j + 1] << " ";
        }
//        cerr << endl;
    }





    int q = nxt();
    while (q--) {
        int r1 = nxt() - 1;
        int c1 = nxt() - 1;

        int r2 = nxt();
        int c2 = nxt();

        int ans = 0;

        ans += SA(r1, c1, r2 - 1, c2 - 1);
        ans += SB(r1, c1, r2 - 1, c2 - 1);
//        cerr << r2 << " " << c2 << endl;
//        cerr << B[r2][c2] << endl;
//        cerr << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
//        cerr << ans << endl;
        ans += SA(r1, c2 - 1, r2 - 1, c2);
        ans += SB(r2 - 1, c1, r2, c2 - 1);

        cout << ans << "\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}