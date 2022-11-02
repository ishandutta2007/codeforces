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
#define LLD "%I64d"
#define eprintf(...)
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
const int N = 55;

int k[2];
bool used[N][N][2];
bool can[N][N][2];

bool calc(int n1, int n2, int step) {
    if (used[n1][n2][step]) {
        return can[n1][n2][step];
    }
    used[n1][n2][step] = true;
    bool& res = can[n1][n2][step];
    if (step == 0) {
        for (int i = 1; i <= k[0] && n1 - i >= 0; ++i) {
            if (!calc(n1 - i, n2, 1 - step)) {
                return res = true;
            }
        }
        return res = false;
    }
    for (int i = 1; i <= k[1] && n2 - i >= 0; ++i) {
        if (!calc(n1, n2 - i, 1 - step)) {
            return res = true;
        }
    }
    return res = false;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n1, n2;
    cin >> n1 >> n2 >> k[0] >> k[1];
    if (calc(n1, n2, 0)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}