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
#include <utility>
#include <random>
#include <chrono>

using namespace std;

#define ll long long

#define cnt(x) (((x) <= n % m ? n / m + 1 : n / m) - (x == 0 ? 1 : 0))

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (((i * i) + (j * j)) % m == 0) {
                ans += (ll)cnt(i) * (ll)cnt(j);
            }
        }
    }
    printf("%lld", ans);
    return 0;
}