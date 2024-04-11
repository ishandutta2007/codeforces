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
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 111;
const int K = 30;

int k;
int row[N], l[K], r[K];
char field[3][N];
bool can[N][3];

inline bool check(int x, int y, int t) {
    for (int i = 0; i < k; ++i) {
        if (row[i] == x) {
            int cl = l[i] - 2 * t, cr = r[i] - 2 * t;
            if (cl <= y && y <= cr) {
                return false;
            }
        }
    }
    return true;
}

inline void solve() {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &field[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            can[i][j] = false;
        }
    }
    k = 0;
    for (int i = 0; i < 3; ++i) {
        int j = 0;
        while (j < n) {
            if (!(field[i][j] >= 'A' && field[i][j] <= 'Z')) {
                ++j;
                continue;
            }
            int z = j;
            while (z + 1 < n && field[i][z + 1] >= 'A' && field[i][z + 1] <= 'Z') {
                ++z;
            }
            row[k] = i;
            l[k] = j;
            r[k++] = z;
            j = z + 1;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (field[i][0] == 's') {
            can[0][i] = true;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (can[i][j] && check(j, i + 1, i)) {
                if (check(j, i + 1, i + 1)) {
                    can[i + 1][j] = true;
                }
                if (j > 0 && check(j - 1, i + 1, i) && check(j - 1, i + 1, i + 1)) {
                    can[i + 1][j - 1] = true;
                }
                if (j + 1 < 3 && check(j + 1, i + 1, i) && check(j + 1, i + 1, i + 1)) {
                    can[i + 1][j + 1] = true;
                }
            }
        }
    }
    if (can[n - 1][0] || can[n - 1][1] || can[n - 1][2]) {
        puts("YES");
    } else {
        puts("NO");
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}