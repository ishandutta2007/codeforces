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

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;
int a[200005];
queue<int> bitloc[25];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        for (int j = 0; j < 20; j++) {
            if (a[i] & (1 << j)) bitloc[j].push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 20; j++) {
            if (a[i] & (1 << j)) continue;
            bool found = false; int loc = 0;
            while (!bitloc[j].empty()) {
                loc = bitloc[j].front(); bitloc[j].pop();
                if (loc > i && (a[loc] & (1 << j))) {
                    found = true; break;
                }
            }
            if (!found) continue;
            a[i] |= (1 << j); a[loc] ^= (1 << j);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (ll)a[i] * (ll)a[i];
    }
    printf("%lld", ans);
    return 0;
}