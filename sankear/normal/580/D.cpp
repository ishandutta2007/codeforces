#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pbk pop_back
#define all(x) (x).begin(), (x).end()
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define prev _prev
#define next _next
#define rank _rank
#define hash _hash
#define left _left
#define right _right

#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = 18;

int a[N];
int g[N][N];
ll dp[(1 << N)][N];

inline void update(ll& a, ll b) {
    if (b > a) {
        a = b;
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x;
        --y;
        g[x][y] = max(g[x][y], c);
    }
    for (int i = 0; i < n; ++i) {
        dp[(1 << i)][i] = a[i];
    }
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) == 0) {
                continue;
            }
            for (int z = 0; z < n; ++z) {
                if ((i & (1 << z)) == 0) {
                    update(dp[(i | (1 << z))][z], dp[i][j] + a[z] + g[j][z]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) != 0) {
                ++cnt;
            }
        }
        if (cnt == m) {
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}