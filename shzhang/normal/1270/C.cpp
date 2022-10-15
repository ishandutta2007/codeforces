#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long

void work(void)
{
    //vector<ll> a;
    int n;
    scanf("%d", &n);
    ll sum = 0;
    ll xorval = 0;
    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        //a.push_back(x);
        sum += x;
        xorval ^= x;
    }
    xorval *= 2LL;
    ll ans[3] = {0, 0, 0};
    ans[0] = (1LL << 55LL) + (sum & 1LL);
    xorval ^= (ans[0] << 1LL);
    sum += ans[0];
    ans[1] = ans[2] = (xorval - sum) / 2LL;
    printf("3\n%lld %lld %lld\n", ans[0], ans[1], ans[2]);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}