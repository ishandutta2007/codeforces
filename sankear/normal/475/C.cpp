#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = 1010;

int n, m;
char a[N][N];
int sum[N][N];
bool used[N][N];

inline int get_sum(int x1, int y1, int x2, int y2) {
    int res = sum[x2][y2];
    if (x1 > 0) {
        res -= sum[x1 - 1][y2];
    }
    if (y1 > 0) {
        res -= sum[x2][y1 - 1];
    }
    if (x1 > 0 && y1 > 0) {
        res += sum[x1 - 1][y1 - 1];
    }
    return res;
}

inline bool good(int x, int y, int w, int h) {
    return get_sum(x, y, x + w - 1, y + h - 1) == w * h;
}

inline bool check(int x, int y, int w, int h) {
    if (w < 1 || h < 1 || x + w - 1 >= n || y + h - 1 >= m) {
        return false;
    }
    cerr << x << " " << y << " " << w << " " << h << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            used[i][j] = false;
        }
    }
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            used[x + i][y + j] = true;
        }
    }
    for (;;) {
        cerr << "go " << x << " " << y << endl;
        // x
        bool fl = false;
        if (x + w < n && good(x + 1, y, w, h)) {
            for (int i = 0; i < h; ++i) {
                used[x + w][y + i] = true;
            }
            ++x;
            fl = true;
        }
        if (fl) {
            continue;
        }
        if (y + h < m && good(x, y + 1, w, h)) {
            for (int i = 0; i < w; ++i) {
                used[x + i][y + h] = true;
            }
            ++y;
            fl = true;
        }
        if (fl) {
            continue;
        }
        break;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X' && !used[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    gets(a[0]);
    for (int i = 0; i < n; ++i) {
        gets(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i][j] = (a[i][j] == 'X');
            if (i > 0) {
                sum[i][j] += sum[i - 1][j];
            }
            if (j > 0) {
                sum[i][j] += sum[i][j - 1];
            }
            if (i > 0 && j > 0) {
                sum[i][j] -= sum[i - 1][j - 1];
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X') {
                int x1 = i, y1 = j;
                while (x1 + 1 < n && a[x1 + 1][y1] == 'X') {
                    ++x1;
                }
                int x2 = i, y2 = j;
                while (y2 < m && a[x2][y2 + 1] == 'X') {
                    ++y2;
                }
                int x = x1, y = y1;
                while (y < m) {
                    if (x + 1 < n && a[x + 1][y] == 'X') {
                        if (check(i, j, x - x2 + 1, y2 - y + 1)) {
                            ans = min(ans, (x - x2 + 1) * (y2 - y + 1));
                        }
                        break;
                    }
                    ++y;
                }
                x = x2;
                y = y2;
                while (x < n) {
                    if (y + 1 < m && a[x][y + 1] == 'X') {
                        if (check(i, j, x1 - x + 1, y - y1 + 1)) {
                            ans = min(ans, (x1 - x + 1) * (y - y1 + 1));
                        }
                        break;
                    }
                    ++x;
                }
                if (check(i, j, 1, y2 - j + 1)) {
                    ans = min(ans, y2 - j + 1);
                }
                if (check(i, j, x1 - i + 1, 1)) {
                    ans = min(ans, x1 - i + 1);
                }
                if (ans == inf) {
                    cout << -1 << endl;
                    return 0;
                }
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}