#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

int T, n;
ll a[300005];
ll b[300005];
bool dep[300005];

int main()
{
    scanf("%d", &T);
    for (int data = 1; data <= T; data++) {
        scanf("%d", &n);
        ll minb = 100000000000000LL;
        ll totala = 0; ll total_damage = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", a + i, b + i);
            minb = min(minb, b[i]); totala += a[i];
        }
        ll min_damage = 100000000000000LL;
        for (int i = 1; i <= n; i++) {
            total_damage += min(b[i], a[i == n ? 1 : i+1]);
            min_damage = min(min_damage, min(b[i], a[i == n ? 1 : i+1]));
        }
        printf("%lld\n", totala - total_damage + min_damage);
    }
    return 0;
}