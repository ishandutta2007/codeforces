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
#define LLD "%I64d"

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
const double eps = 1e-4;
const double pi = 4 * atan(double(1));
const int N = int(1e3) + 100;

int n;
int a[N][N], d[N][N], p2[N][N], p5[N][N];

inline int calc(int p[N][N], int val) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cur = 0, ch = a[i][j];
            if (ch > 0) {
                while (ch % val == 0) {
                    ++cur;
                    ch /= val;
                }
            } else {
                cur = inf;
            }
            if (i == 0 && j == 0) {
                d[i][j] = cur;
                continue;
            }
            d[i][j] = inf;
            if (i > 0 && d[i - 1][j] + cur < d[i][j]) {
                d[i][j] = d[i - 1][j] + cur;
                p[i][j] = 1;
            }
            if (j > 0 && d[i][j - 1] + cur < d[i][j]) {
                d[i][j] = d[i][j - 1] + cur;
                p[i][j] = 0;
            }
        }
    }
    return d[n - 1][n - 1];
}

void path(int p[N][N], int x, int y) {
    if (x == 0 && y == 0) {
        return;
    }
    if (p[x][y] == 0) {
        path(p, x, y - 1);
        printf("R");
    } else {
        path(p, x - 1, y);
        printf("D");
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans2 = calc(p2, 2), ans5 = calc(p5, 5), x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }
    if (x != -1 && 1 < min(ans2, ans5)) {
        puts("1");
        for (int i = 0; i < x; ++i) {
            printf("D");
        }
        for (int i = 0; i < n - 1; ++i) {
            printf("R");
        }
        for (int i = 0; i < n - 1 - x; ++i) {
            printf("D");
        }
        puts("");
        return 0;
    }
    if (ans2 < ans5) {
        cout << ans2 << endl;
        path(p2, n - 1, n - 1);
    } else {
        cout << ans5 << endl;
        path(p5, n - 1, n - 1);
    }
    puts("");
    return 0;
}