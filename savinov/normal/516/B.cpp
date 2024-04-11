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

char s[2000][2001];
int degree[2000][2000];

int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int get(int x, int y) {
    int res = 0;
    for (int k = 0; k < 4; ++k) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
        if (s[xx][yy] != '*') ++res;
    }
    return res;
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

    n = nxt(), m = nxt();
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    queue <PII> q;
    int cc = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '*') continue;
            degree[i][j] = get(i, j);
            if (degree[i][j] == 0) {
                puts("Not unique");
                return 0;
            }
            ++cc;
            if (degree[i][j] == 1) {
                q.push(mp(i, j));
            }
        }
    }
    if (cc % 2 == 1) {
        puts("Not unique");
        return 0;
    }

    while (!q.empty()) {
        PII v = q.front();
        q.pop();
        int x = v.x;
        int y = v.y;

        if (s[v.x][v.y] != '.') continue;

        int p = -1;

        for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (s[xx][yy] == '.') p = k;
        }
        if (p == -1) {
            puts("Not unique");
            return 0;
        }
        int xx = x + dx[p];
        int yy = y + dy[p];

        cc -= 2;

        degree[xx][yy]--;
        degree[x][y]--;

        if (p == 0) {
            s[x][y] = '>';
            s[xx][yy] = '<';
        }
        if (p == 1) {
            s[x][y] = '<';
            s[xx][yy] = '>';
        }
        if (p == 2) {
            s[x][y] = 'v';
            s[xx][yy] = '^';
        }
        if (p == 3) {
            s[x][y] = '^';
            s[xx][yy] = 'v';
        }

        for (int k = 0; k < 4; ++k) {
            int xxx = x + dx[k];
            int yyy = y + dy[k];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (s[xxx][yyy] == '.') {
                degree[xxx][yyy]--;
                if (degree[xxx][yyy] == 1) {
                    q.push(mp(xxx, yyy));
                }
            }
        }

        for (int k = 0; k < 4; ++k) {
            int xxx = xx + dx[k];
            int yyy = yy + dy[k];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (s[xxx][yyy] == '.') {
                degree[xxx][yyy]--;
                if (degree[xxx][yyy] == 1) {
                    q.push(mp(xxx, yyy));
                }
            }
        }
    }

    if (cc != 0) {
        puts("Not unique");
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        puts(s[i]);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}