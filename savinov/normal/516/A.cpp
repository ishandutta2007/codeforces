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

long long cnt[10];

int f[10][10];

int ans[100000];

void rec(int pos) {
    char ok = true;
    for (int i = 0; i < 10; ++i) {
        if (cnt[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        sort(ans, ans + pos, greater<int>());
        for (int i = 0; i < pos; ++i) {
            cout << ans[i];
        }
        cout << "\n";
        exit(0);
    }
    int r = 9;
    while (!cnt[r]) {
        --r;
    }
    for (int i = r; i < 10; ++i) {
        char can = true;
        for (int j = 0; j < 10; ++j) {
            if (cnt[j] < f[i][j]) {
                can = false;
                break;
            }
        }
        if (can) {
            for (int j = 0; j < 10; ++j) {
                cnt[j] -= f[i][j];
            }
            ans[pos] = i;
            rec(pos + 1);
            for (int j = 0; j < 10; ++j) {
                cnt[j] += f[i][j];
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "strings"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    //cout << sizeof(tt) + sizeof(qq) + sizeof(ff) + sizeof(used) + sizeof(ans) << "\n";

    clr(cnt);
    int n = nxt();

    for (int i = 2; i < 10; ++i) {
        memcpy(f[i], f[i - 1], sizeof(f[i]));
        int x = i;
        for (int j = 2; j < 10; ++j) {
            while (x > 0 && x % j == 0) {
                f[i][j]++;
                x /= j;
            }
        }
    }
    char s[n + 1];
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        int x = s[i] - '0';
        for (int j = 0; j < 10; ++j) {
            cnt[j] += f[x][j];
        }
    }

    rec(0);

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}