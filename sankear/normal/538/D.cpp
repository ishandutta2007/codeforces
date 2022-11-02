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
#include <stack>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || _WIN64 || __WIN32__ || __WIN64__
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
typedef long double ld;
typedef complex<double> tc;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 111;

int n;
char a[N][N];
bool used[N][N];
bool can[N * 2][N * 2];

inline bool good(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &a[i][j]);
        }
    }
    for (int i = -(n - 1); i < n; ++i) {
        for (int j = -(n - 1); j < n; ++j) {
            can[i + n][j + n] = true;
            for (int z = 0; z < n && can[i + n][j + n]; ++z) {
                for (int h = 0; h < n; ++h) {
                    if (a[z][h] != 'o') {
                        continue;
                    }
                    int nz = z + i, nh = h + j;
                    if (good(nz, nh) && a[nz][nh] != 'o') {
                        if (a[nz][nh] == '.') {
                            can[i + n][j + n] = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != 'o') {
                continue;
            }
            for (int z = -(n - 1); z < n; ++z) {
                for (int h = -(n - 1); h < n; ++h) {
                    if (!can[z + n][h + n]) {
                        continue;
                    }
                    int ni = i + z, nj = j + h;
                    if (good(ni, nj) && a[ni][nj] != 'o') {
                        used[ni][nj] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'x') {
                if (!used[i][j]) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    for (int i = -(n - 1); i < n; ++i) {
        for (int j = -(n - 1); j < n; ++j) {
            if (i == 0 && j == 0) {
                printf("o");
                continue;
            }
            if (can[i + n][j + n]) {
                printf("x");
            } else {
                printf(".");
            }
        }
        puts("");
    }
    return 0;
}