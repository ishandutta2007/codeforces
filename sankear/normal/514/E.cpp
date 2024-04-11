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
#define LLD "%lld"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define LLD "%I64d"
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
const int N = 101;
const int MOD = int(1e9) + 7;
const ll MOD2 = 1LL * MOD * MOD;

int a[N + 10];
int init[N][N], res[N][N];
ll tmp[N][N];

inline void mult(int a[N][N], int b[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tmp[i][j] = 0;
            for (int z = 0; z < N; ++z) {
                tmp[i][j] += 1LL * a[i][z] * b[z][j];
                if (tmp[i][j] >= MOD2) {
                    tmp[i][j] -= MOD2;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = tmp[i][j] % MOD;
        }
    }
}

void calc(int x) {
    if (x == 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res[i][j] = 0;
            }
            res[i][i] = 1;
        }
        return;
    }
    if (x == 1) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res[i][j] = init[i][j];
            }
        }
        return;
    }
    if (x % 2 == 0) {
        calc(x / 2);
        mult(res, res);
    } else {
        calc(x - 1);
        mult(res, init);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        ++a[cur];
    }
    for (int i = 1; i < N; ++i) {
        init[0][i - 1] = a[i];
    }
    init[0][N - 1] = 1;
    for (int i = 1; i < N - 1; ++i) {
        init[i][i - 1] = 1;
    }
    init[N - 1][N - 1] = 1;
    calc(x);
    cout << (res[0][0] + res[0][N - 1]) % MOD << endl;
    return 0;
}