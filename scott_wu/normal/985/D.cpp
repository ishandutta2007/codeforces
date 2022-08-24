#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

ll N, H;

bool works (ll x)
{
    if (x >= 3e9) return true;
    if (x <= H)
    {
        if (x * (x + 1) / 2 >= N) return true;
        return false;
    }
    ll m = (x - H + 1) / 2, h = (x + H) / 2;
    ll tot = H * m + (m * (m - 1)) / 2 + (h * (h + 1)) / 2;
    return tot >= N;
}

int main()
{
    cin >> N >> H;
    ll lo = 0, hi = 1e18;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (works(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
}