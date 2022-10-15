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

int n;
ll a[200005];
ll t[200005];
int perm[200005];
ll tmp[200005];
ll goal[200005];

bool cmp(int A, int b)
{
    return a[A] < a[b] || (a[A] == a[b] && t[A] > t[b]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= n; i++) scanf("%lld", t + i);
    for (int i = 1; i <= n; i++) perm[i] = i;
    sort(perm + 1, perm + n + 1, cmp);
    for (int i = 1; i <= n; i++) tmp[i] = a[perm[i]];
    for (int i = 1; i <= n; i++) a[i] = tmp[i];
    for (int i = 1; i <= n; i++) tmp[i] = t[perm[i]];
    for (int i = 1; i <= n; i++) t[i] = tmp[i];
    ll ans = 0;
    int curend = 1;
    priority_queue<ll> prices;
    ll curtotal = 0;
    a[n + 1] = 2000000000;
    while (curend <= n) {
        while (1) {
            prices.push(t[curend]); curtotal += t[curend];
            curend++;
            if (curend > n || a[curend] != a[curend - 1]) break;
        }
        ll psiz = (ll)prices.size();
        for (int i = 1; i <= min(psiz, a[curend] - a[curend-1]); i++) {
            curtotal -= prices.top(); prices.pop();
            ans += curtotal;
        }
    }
    while (!prices.empty()) {
        curtotal -= prices.top(); prices.pop();
        ans += curtotal;
    }
    printf("%lld", ans);
    return 0;
}