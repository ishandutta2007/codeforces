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

vector <int> L[100];
vector <int> R[100];
vector <int> G[100];

int dp[100][100];

int MIL[100], MAL[100];
int MIR[100], MAR[100];

int can(int l, int r) {
    if (l > r) {
        return 1;
    }
    int & res = dp[l][r];
    if (res != -1) {
        return res;
    }
    res = 0;
    if (MIL[l] <= l || MIR[l] <= l || MAL[l] > r || MAR[l] > r) {
        return 0;
    }
    if (MAL[l] > r) {
        return 0;
    }
    int minL = max(MAL[l], l);
    int maxR = min(MIR[l], r + 1);

    for (int p = minL; p < maxR; ++p) {
        if (can(l + 1, p) && can(p + 1, r)) {
            return res = 1;
        }
    }
    return res = 0;
}



void rec(int l, int r) {
    if (l > r) {
        return;
    }
    int minL = max(MAL[l], l);
    int maxR = min(MIR[l], r + 1);

    for (int p = minL; p < maxR; ++p) {
        if (can(l + 1, p) && can(p + 1, r)) {
            rec(l + 1, p);
            cout << l + 1 << " ";
            rec(p + 1, r);
            return;
        }
    }
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "guard"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n, c;
    cin >> n >> c;

    memset(dp, 255, sizeof(dp));

    for (int i = 0; i < n; ++i) {
        MIL[i] = INT_MAX;
        MIR[i] = INT_MAX;
        MAL[i] = INT_MIN;
        MAR[i] = INT_MIN;
    }

    for (int i = 0; i < c; ++i) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        string s;
        cin >> s;
        if (a > b) {
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }

        if (s == "LEFT") {
            L[a].pb(b);
            MIL[a] = min(MIL[a], b);
            MAL[a] = max(MAL[a], b);
        }
        if (s == "RIGHT") {
            R[a].pb(b);
            MIR[a] = min(MIR[a], b);
            MAR[a] = max(MAR[a], b);
        }
    }

    int res = can(0, n - 1);

    if (!res) {
        cout << "IMPOSSIBLE\n";
    } else {
        rec(0, n - 1);
        cout << "\n";
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
};