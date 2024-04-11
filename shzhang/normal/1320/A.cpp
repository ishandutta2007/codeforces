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

ll b[200005];
ll bval[1000005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", b + i);
        bval[b[i] + 400000 - i] += b[i];
    }
    ll ans = 0;
    for (int i = 0; i <= 1000000; i++) {
        ans = max(ans, bval[i]);
    }
    printf("%lld", ans);
    return 0;
}