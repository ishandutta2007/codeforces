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

char u1[1000][1000];
char u2[1000][1000];

int n;

int ans[1000][1000];

void rec(int x, int y) {
    if (y == x) {
        rec(x + 1, 0);
        return;
    }
    if (x == n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (u1[x][i]) continue;
        if (u1[y][i]) continue;
        if (u2[y][i]) continue;
        if (u2[x][i]) continue;
        ans[x][y] = ans[y][x] = i;
        u1[x][i] = u1[y][i] = 1;
        u2[x][i] = u2[y][i] = 1;
        rec(x, y + 1);
        u1[x][i] = u1[y][i] = 0;
        u2[x][i] = u2[y][i] = 0;
    }
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "war"
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    n = nxt();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                cout << 0 << " ";
            } else {
                int res = 1 + (i + j + n - 2) % (n - 1);
                if (j == n - 1) {
                    if (i < n / 2) {
                        res = (res + i) % n;
                    } else {
                        res = (res + i + 1) % n;
                    }
                }
                cout << res << " ";
            }
        }
        cout << "\n";
    }

    for (int i = 0; i < n - 1; ++i) {
        int res = 1 + (i + n - 1 + n - 2) % (n - 1);
        if (i < n / 2) {
            cout << (res + i) % n << " ";
        } else {
            cout << (res + i + 1) % n << " ";
        }
    }
    cout << "0\n";


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}