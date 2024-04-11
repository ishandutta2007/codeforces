#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }

    vector<int> dp(n), l(n), r(n);

    forn(i, n) {
        l[i] = max(0, i - k);
        r[i] = min(n - 1, i + k);
        dp[i] = r[i] - l[i] + 1;
        if (a[i] > 0) {
            int prev = a[i] - 1;
            int twice = max(0, r[prev] - l[i] + 1);
            dp[i] += dp[prev] - twice;
        }
    }

    forn(i, n) {
        cout << dp[i] << ' ';
    }

    cout << '\n';
    
    return 0;
}