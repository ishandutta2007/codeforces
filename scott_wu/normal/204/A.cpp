#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

bool good (ll x)
{
    ll l = x % 10;
    while (x >= 10)
        x /= 10;
    return (l == x);
}

ll find (ll x)
{
    if (x < 10) return x;
    ll ans = (x / 10) - 1 + 9;
    for (ll i = (x / 10) * 10; i <= x; i++)
        if (good (i))
            ans++;
    return ans;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << find (b) - find (a-1) << "\n";
    //system ("Pause");
    return 0;
}