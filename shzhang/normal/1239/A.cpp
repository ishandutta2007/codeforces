#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define ll long long
#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int f[100005];

int main()
{
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 100000; i++) {
        f[i] = f[i-1] + f[i-2];
        if (f[i] >= MOD) f[i] -= MOD;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", (int)((mul((f[n] + f[m]) % MOD, 2) + MOD - 2) % MOD));
    return 0;
}