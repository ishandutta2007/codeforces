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
const int MAXN = 510;
const int MAXM = MAXN * MAXN;

int a[MAXM];
int ans[MAXN];

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    scanf("%d", &n);
    int m = n * n;
    multiset<int, greater<int> > s;
    FOR(i, m) {
        int a;
        scanf("%d", &a);
        s.insert(a);
    }
//    sort(a, a + n);
//    reverse(a, a + n);
    int p = 0;
    FOR(i, n) {
        ans[i] = *s.begin();
        s.erase(s.begin());
//        cerr << ans[i] << '\n';
        FOR(j, i) {
            int g = __gcd(ans[i], ans[j]);
   //         cerr << g << ' ' ;
            FOR(_, 2)
                s.erase(s.find(g));
        }
     //   cerr << '\n';
    }
    FOR(i, n)
        printf("%d ", ans[i]);
    printf("\n");


    return 0;
}