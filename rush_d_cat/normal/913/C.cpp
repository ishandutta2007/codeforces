#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define rd(x) scanf("%d", &x)
#define rd2(x, y) scanf("%d %d", &x, &y)
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i=(a);i<=(b);i++)
#define dd(x) cout << #x << " = " << x << endl;
#define max(x, y) (x > y ? x : y)
typedef pair<int, int> pii;
typedef long long LL;
const LL INF = 1000000007;
const LL MOD = 1000000007;
const int N = 100000+10;

LL n, L;
LL c[N], dp[36];

int main() {
    scanf("%lld %lld", &n, &L);
    rep(i, 0, n-1) scanf("%lld", &c[i]);
    rep(i, 0, 35) dp[i] = 1e18+7;

    rep(i, 0, 35) {
        if (i < n) {
            dp[i] = min(dp[i], c[i]); 
        }
        if (i > 0)
            dp[i] = min(dp[i], 2L * dp[i-1]);
    }
    for (int i=34;i>=0;i--)
        dp[i] = min(dp[i], dp[i+1]);

    LL ans = 1e18+7;



    for (LL i = 35; i >= 0; i --) {

        if ((L>>i) & 1) break;
        for (LL j = i; j >= 0; j --) {
            LL sum = 0, cost = 0;            
            for (LL k = i; k >= j; k --) {
                if ((L>>k)&1) {
                    sum += (1LL<<k);
                    cost += dp[k];
                }
            }

            if (sum>=L) ans=min(ans,cost);

            LL minc = 1e18+7;
            for (LL k = j; k >= 0; k --) {
                if (k!=j && (L>>k)&1) break;
                minc = min(minc, dp[k]);
            }
            ans = min(ans, cost+minc);
        }
    }

    cout << ans << endl;

}