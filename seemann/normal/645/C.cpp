#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5 + 200;
char s[MAXN];
int p[MAXN];

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, k; 
    scanf("%d%d", &n, &k);
    k++;
    scanf("%s", s);
    int m = 0;
    forn(i, n) {
        if (s[i] == '0') {
            p[m++] = i;
        }
    }
    int ans = INF;
    forn(i, m - k + 1) {
        int mid = (p[i] + p[i + k - 1]) / 2;
        int t = upper_bound(p + i, p + i + k, mid) - p;
        ans = min(ans, max(p[t] - p[i], p[i + k - 1] - p[t]));
        t--;
        if (t >= i) {
            ans = min(ans, max(p[t] - p[i], p[i + k - 1] - p[t]));
        }
    }
    cout << ans << '\n';
    return 0;
}