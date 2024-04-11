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

int dp[2][100][100];

int k;

int solve( int player, int a, int b) {
    if (a + b == k) {
        return !(b % 2);
    }
    int & res = dp[player][a][b];
    if (res != -1) {
        return res;
    }
    res = !player;
    if (a && solve(player ^ 1, a - 1, b) == player) {
        return res = player;
    }
    if (b && solve(player ^ 1, a, b - 1) == player) {
        return res = player;
    }
    return res;
}

int solve2(int a, int b, int k) {
    if (a + b == k) {
        return !(b % 2);
    }
    if (a >= b) {
        if (k <= a - b || k % 2 == (a - b) % 2) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (k < b - a) {
            return k % 2 == 0;
        } else {
            if (a % 2 != b % 2) {
                return (k > b - a && (k % 2 == 1));
            } else {
                return k >= b - a && (k % 2 == 0);
            }
        }
    }
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

    for (int a = 0; a <= 50; ++a) {
        for (int b = 0; b <= 50; ++b) {
            for (k = 1; k <= a + b; ++k) {
                memset(dp, 255, sizeof(dp));
                assert(solve(0, a, b) == solve2(a, b, k));
            }
        }
    }

    int n = nxt();
    int k = nxt();

    int a = 0;
    int b = 0;

    for (int i = 0; i < n; ++i) {
        int x = nxt() % 2;
        if (x == 0) {
            ++a;
        } else {
            ++b;
        }
    }

    if (solve2(a, b, k)) {
        cout << "Daenerys\n";
    } else {
        cout << "Stannis\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}