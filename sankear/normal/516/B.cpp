#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 2020;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int n, m, l, r;
bool del[N][N], used[N][N];
char a[N][N], ans[N][N];
pii q[N * N];

inline bool good(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*';
}

inline void fail() {
    puts("Not unique");
    exit(0);
}

inline void mark(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        if (y1 > y2) {
            swap(y1, y2);
        }
        ans[x1][y1] = '<';
        ans[x2][y2] = '>';
        return;
    }
    if (x1 > x2) {
        swap(x1, x2);
    }
    ans[x1][y1] = '^';
    ans[x2][y2] = 'v';
}

inline void add(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!good(nx, ny)) {
            continue;
        }
        if (del[nx][ny] || used[nx][ny]) {
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < 4; ++j) {
            int cx = nx + dx[j], cy = ny + dy[j];
            if (good(cx, cy) && !del[cx][cy]) {
                ++cnt;
            }
        }
        if (cnt == 0) {
            fail();
        }
        if (cnt == 1) {
            used[nx][ny] = true;
            q[r++] = mp(nx, ny);
        }
    }
}

int main() {
    cerr << (sizeof(a) + sizeof(ans) + sizeof(used) + sizeof(del) + sizeof(q)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    gets(a[0]);
    for (int i = 0; i < n; ++i) {
        gets(a[i]);
    }
    l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = a[i][j];
            if (a[i][j] == '*') {
                continue;
            }
            int cnt = 0;
            for (int z = 0; z < 4; ++z) {
                int ni = i + dx[z], nj = j + dy[z];
                if (!good(ni, nj)) {
                    continue;
                }
                ++cnt;
            }
            if (cnt == 0) {
                fail();
            }
            if (cnt == 1) {
                used[i][j] = true;
                q[r++] = mp(i, j);
            }
        }
    }
    while (l < r) {
        int x = q[l].fs, y = q[l++].sc;
        if (del[x][y]) {
            continue;
        }
        int nx = -1, ny = -1;
        for (int i = 0; i < 4; ++i) {
            int cx = x + dx[i], cy = y + dy[i];
            if (!good(cx, cy)) {
                continue;
            }
            if (del[cx][cy]) {
                continue;
            }
            assert(nx == -1);
            nx = cx;
            ny = cy;
        }
        if (nx == -1) {
            fail();
        }
        del[x][y] = del[nx][ny] = true;
        mark(x, y, nx, ny);
        add(x, y);
        add(nx, ny);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '*' && !del[i][j]) {
                fail();
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        puts(ans[i]);
    }
    return 0;
}