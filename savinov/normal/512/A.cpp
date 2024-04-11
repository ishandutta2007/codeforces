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


char color[26];

vector <int> g[26];

vector <int> order;

void dfs(int v) {
    color[v] = 1;
    for (int to : g[v]) {
        if (color[to] == 1) {
            puts("Impossible");
            exit(0);
        }
        if (color[to] == 0) {
            dfs(to);
        }
    }
    color[v] = 2;
    order.push_back(v);
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

    int n;
    cin >> n;

    string s[n];

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }


    for (int i = 0; i + 1 < n; ++i) {
        int l = 0;
        while (l < (int)s[i].length() && l < (int)s[i + 1].length() && s[i][l] == s[i + 1][l]) {
            ++l;
        }
        if (l == s[i + 1].length()) {
            puts("Impossible");
            return 0;
        }
        if (l < (int)s[i].length()) {
            //cerr << s[i][l] << " " << s[i + 1][l] << endl;
            g[s[i][l] - 'a'].pb(s[i + 1][l] - 'a');
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (!color[i]) {
            dfs(i);
        }
    }
    reverse(all(order));

    for (int i = 0; i < 26; ++i) {
        cout << (char)('a' + order[i]);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
};