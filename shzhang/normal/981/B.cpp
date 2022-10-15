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
#include <map>

using namespace std;

#define ll long long

map<int, int> mp;

int n, m;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, x;
        scanf("%d%d", &a, &x);
        mp[a] = max(mp[a], x);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int a, x;
        scanf("%d%d", &a, &x);
        mp[a] = max(mp[a], x);
    }
    ll ans = 0;
    for (auto i = mp.begin(); i != mp.end(); i++) {
        ans += (*i).second;
    }
    printf("%lld", ans);
    return 0;
}