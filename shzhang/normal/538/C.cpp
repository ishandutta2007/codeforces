#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int n, m;

ll absolute(ll a)
{
    return a > 0 ? a : -a;
}

int main()
{
    cin >> n >> m;
    ll prevd, prevh, d, h;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        cin >> d >> h;
        if (i != 1) {
            if (absolute(h - prevh) > d - prevd) {
                printf("IMPOSSIBLE"); return 0;
            }
            ans = max(ans, (prevh + h + d - prevd) / 2LL);
        } else {
            ans = max(ans, h + d-1);
        }
        prevd = d; prevh = h;
    }
    ans = max(ans, h + n - d);
    cout << ans;
    return 0;
}