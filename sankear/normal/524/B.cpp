#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e3 + 100;

int n;
int w[N], h[N];

int dp[N][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][max(j, h[i])] = min(dp[i + 1][max(j, h[i])], dp[i][j] + w[i]);
            dp[i + 1][max(j, w[i])] = min(dp[i + 1][max(j, w[i])], dp[i][j] + h[i]);
        }
    }
    int64 ans = linf;
    for (int i = 0; i < N; i++) {
        if (dp[n][i] >= inf) {
            continue;
        }
        ans = min(ans, 1ll * i * dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}