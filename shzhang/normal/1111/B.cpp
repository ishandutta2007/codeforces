#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

#define ll long long

int n, k, m;
int a[100005];

using namespace std;

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    double ans = 0.0;
    ll total_pwr = 0;
    for (int i = n; i >= 1; i--) {
        total_pwr += a[i];
        if (m - i + 1 < 0) continue;
        ans = max(ans, (total_pwr + min((ll)(n-i+1) * (ll)(k), (ll)(m - i + 1))) / (double)(n-i+1));
    }
    printf("%.13f", ans);
    return 0;
}