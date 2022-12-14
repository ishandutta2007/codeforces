#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 30, mod = (int) 0;
int res[N];
int gcd(int x, int y) {
    if (min(x, y) == 0) return x + y;
    return __gcd(x, y);
}
int main() {
    int q;
    memset(res, -1, sizeof res);
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        int b = 0;
        while ((1 << b) <= x) ++b;
        if (((x + 1) & x) == 0) {
            if (res[b] == -1) {
                res[b] = 1;
               for (int j = 2; j * j <= x; ++j)
                   if (x % j == 0) {
                       res[b] = x / j;
                       break;
                   }
            }
            cout << res[b] << '\n';
            continue;
        }
        cout << (1 << b) - 1 << '\n';
    }
}