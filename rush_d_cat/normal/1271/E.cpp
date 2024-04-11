#include <iostream>
using namespace std;
typedef long long LL;
LL n, k;
LL getcnt_even(LL x) {
    LL p = 1, ans = 0;
    while (1) {
        LL l = p * x, r = p * x + 2 * p - 1;
        if (l > n) break;
        ans += (min(r, n) - l + 1);
        if (r >= n) break;
        p *= 2;
    }
    return ans;
}
LL getcnt_odd(LL x) {
    LL p = 1, ans = 0;
    while (1) {
        LL l = p * x, r = p * x + p - 1;
        if (l > n) break;
        ans += (min(r, n) - l + 1);
        if (r >= n) break;
        p *= 2;
    }
    return ans;
}
int main() {
    scanf("%lld%lld", &n, &k);
    LL res = 0;
    {
        LL lef = 1, rig = n / 2 + 1;
        while (rig - lef > 1) {
            LL mid = (lef + rig) >> 1;
            if (getcnt_even(2 * mid) >= k) {
                lef = mid;
            } else {
                rig = mid;
            }
        }
        if (getcnt_even(2 * lef) >= k)
            res = max(res, 2 * lef);
    }
    {
        LL lef = 1, rig = n / 2 + 2;
        while (rig - lef > 1) {
            LL mid = (lef + rig) >> 1;
            if (getcnt_odd(2 * mid - 1) >= k) {
                lef = mid;
            } else {
                rig = mid;
            }
        }
        if (getcnt_odd(2 * lef - 1) >= k)
            res = max(res, 2 * lef - 1);
    }
    cout << res << endl;
}


/*
x is even
[x, x+1]
[2x, 2x+3]
[3x, 3x+7]

x is odd
[x, x]
[2x,2x+1]
[4x,4x+3]
[8x,8x+7]
*/