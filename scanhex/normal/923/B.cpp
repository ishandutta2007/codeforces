#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector <int> v(n), t(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    multiset <ll> s;
    ll add = 0;
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i] - add);
        scanf("%d", &t[i]);
        ll ans = 0;
        while (!s.empty() && *s.begin() + add <= t[i])
        {
            ans += *s.begin() + add;
            s.erase(s.begin());
        }
        ans += s.size() * (ll) t[i];
        add -= t[i];
        printf("%lld ", ans);
    }
    puts("");
}