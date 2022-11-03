/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n, k;
int a[2333];
int dp[2333];

bool check(int m) {
    cont(i, n) dp[i] = i - 1;
    cont(i, n) {
        circ(j, i + 1, n) {
            if(abs(a[j] - a[i]) <= 1ll * (j - i) * m) {
                dp[j] = min(dp[j], dp[i] + (j - i - 1));
            }
        }
    }
    int ans = Inf;
    loop(i, n + 1) ans = min(ans, dp[i] + (n - i));
    return ans <= k;
}

int main() {
    scanf("%d%d", &n, &k);
    if(n > 2000) return 0 & puts("0");
    cont(i, n) scanf("%d", a + i);
    int l = -1, r = 2e9 + 1;
    while(r - l > 1) {
        int m = (ll(l) + r) >> 1;
        if(check(m)) r = m;
        else l = m;
    }
    printf("%d\n", r);
    return 0;
}