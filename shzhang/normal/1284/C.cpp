#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
#define mul(a, b) (((ll)(a) * (ll)(b)) % m)

int n, m;

int fact[250005];

int f(int len)
{
    return mul(n - len + 1, mul(fact[len], fact[n-len]));
}

int main()
{
    int ans = 0;
    scanf("%d%d", &n, &m);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mul(i, fact[i-1]);
    for (int i = 1; i <= n; i++) {
        ans += mul(n - i + 1, f(i));
        if (ans >= m) ans -= m;
    }
    printf("%d", ans);
    return 0;
}