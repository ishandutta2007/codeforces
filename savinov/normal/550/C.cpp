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

    string s;
    cin >> s;

    int can[s.length() + 1][8];
    int p[s.length() + 1][8];
    memset(p, 255, sizeof(p));
    memset(can, 0x80, sizeof(can));

    can[0][0] = 0;

    for (int i = 0; i < (int)s.length(); ++i) {
        for (int j = 0; j < 8; ++j) {
            if (can[i][j] >= 0) {
                if (can[i + 1][(j * 10 + s[i] - '0') % 8] < can[i][j] + 1) {
                    can[i + 1][(j * 10 + s[i] - '0') % 8] = can[i][j] + 1;
                    p[i + 1][(j * 10 + s[i] - '0') % 8] = j;
                }
                if (can[i + 1][j] < can[i][j]) {
                    can[i + 1][j] = can[i][j];
                    p[i + 1][j] = -1;
                }
            }
        }
    }

    //cout << can[s.length()][0] << "\n";

    if (can[s.length()][0] <= 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int x = s.length();

        vector <int> ans;

        int r = 0;

        while (x > 0) {
            if (p[x][r] != -1) {
                ans.push_back(s[x - 1] - '0');
                r = p[x][r];
            }
            --x;
        }
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(all(ans));

        for (int x : ans) {
            cout << x;
        }
        cout << "\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}