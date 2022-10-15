#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

#define ll long long

ll n, H;

ll blocks(ll len)
{
    if (len <= H) {
        return (len * (len + 1)) / 2;
    } else {
        ll before_H = ((H-1)*H)/2;
        ll ans = before_H;
        ll layers_after_H = len - H + 1;
        if (layers_after_H % 2LL == 1LL) {
            ans += H + layers_after_H / 2;
            layers_after_H--;
        }
        ans += (H + H + layers_after_H / 2 - 1) * (layers_after_H / 2);
        return ans;
    }
}

int main()
{
    cin >> n >> H;
    ll l = 1; ll r = 2500000000LL;
    while (l < r) {
        ll mid = (l + r) / 2 + 1;
        /* Find last <= n */
        if (blocks(mid) > n) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    if (blocks(l) < n) l++;
    cout << l;
    return 0;
}