#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n, k;
int p[200005];

int main()
{
    vector<int> hpos;
    scanf("%d%d", &n, &k);
    ll mpv = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i);
        if (p[i] > n - k) {
            mpv += (ll)p[i];
            hpos.push_back(i);
        }
    }
    sort(hpos.begin(), hpos.end());
    int ans = 1;
    for (int i = 0; i + 1 < hpos.size(); i++) {
        ans = mul(ans, hpos[i+1] - hpos[i]);
    }
    printf("%lld %d", mpv, ans);
    return 0;
}