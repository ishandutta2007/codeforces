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

    long long m = nxt();

    long long h1 = nxt(), a1 = nxt();
    long long x1 = nxt(), y1 = nxt();

    long long h2 = nxt(), a2 = nxt();
    long long x2 = nxt(), y2 = nxt();

    int used1[m];
    clr(used1);

    long long x = h1;

    long long p1 = -1;
    long long f1 = -1;
    long long ok1 = -1;

    for (int i = 1; i <= m + 1; ++i) {
        if (used1[x]) {
            p1 = i - used1[x];
            ok1 = used1[x] <= f1;
            break;
        }
        if (x == a1 && f1 == -1) {
            f1 = i;
        }
        used1[x] = i;
        x = (x * x1 + y1) % m;
    }

    long long p2 = -1;
    long long f2 = -1;
    long long ok2 = 0;

    clr(used1);

    x = h2;

    for (int i = 1; i <= m + 1; ++i) {
        if (used1[x]) {
            p2 = i - used1[x];
            ok2 = used1[x] <= f2;
            break;
        }
        if (x == a2 && f2 == -1) {
            f2 = i;
        }
        used1[x] = i;
        x = (x * x2 + y2) % m;
    }

    cerr << f1 << " " << f2 << "\n";
    cerr << p1 << " " << p2 << "\n";

    if (f1 == -1 || f2 == -1) {
        cout << "-1\n";
        return 0;
    }

    if (f1 == f2) {
        cout << f1 - 1 << "\n";
        return 0;
    }


    long long mm = ok1 ? m + 1 : 0;

    for (int s = 0; s <= mm; ++s) {
        long long t = f1 - 1 + p1 * s - (f2 - 1);
        if (t >= 0 && t % p2 == 0) {
            long long z = t / p2;
            if (ok2 || z == 0) {
                cout << f1 - 1 + p1 * s << "\n";
                return 0;
            }

        }
    }

    cout << "-1\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}