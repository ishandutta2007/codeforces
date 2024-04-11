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
#include <unordered_map>

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
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
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
const int dy[] = { 0, 1, 0, -1 };
const int dx2[] = { -1, 1, 1, -1 };
const int dy2[] = { 1, 1, -1, -1 };

int n, m, l = 0, r = 0;
bool used[N][N];
char a[N][N];
int q[N * N * 2];

inline bool good(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

inline void process(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int cx = x + dx2[i], cy = y + dy2[i];
        if (!good(cx, cy) || a[cx][cy] != '*' || used[cx][cy]) {
            continue;
        }
        int ni = i + 1;
        if (ni >= 4) {
            ni = 0;
        }
        if (a[x + dx[i]][y + dy[i]] == '.' && a[x + dx[ni]][y + dy[ni]] == '.') {
            used[cx][cy] = true;
            q[r++] = cx;
            q[r++] = cy;
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    gets(a[0]);
    for (int i = 0; i < n; ++i) {
        gets(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                process(i, j);
            }
        }
    }
    while (l < r) {
        int x = q[l++], y = q[l++];
        a[x][y] = '.';
        process(x, y);
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (good(nx, ny) && a[nx][ny] == '.') {
                process(nx, ny);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        puts(a[i]);
    }
    return 0;
}