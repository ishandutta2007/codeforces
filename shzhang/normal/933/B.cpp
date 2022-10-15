#include <cstdio>

using namespace std;

#define ll long long

ll ans[500005];

int main()
{
    ll p, k;
    scanf("%lld%lld", &p, &k);
    int cur = 0;
    while (p) {
        ans[cur] = p % k;
        p /= k; cur++;
    }
    for (int i = 0; i <= 500000; i++) {
        if (!ans[i]) continue;
        ans[i+1] += ans[i] / k;
        ans[i] %= k;
        if (i % 2 && ans[i]) {
            ans[i+1]++;
            ans[i] = k - ans[i];
        }
    }
    int lastval = 0;
    for (int i = 0; i <= 500000; i++) {
        if (ans[i]) lastval = i;
    }
    printf("%d\n", lastval + 1);
    for (int i = 0; i <= lastval; i++) printf("%lld ", ans[i]);
    return 0;
}