#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 7;

ll gcd(ll x, ll y) {
    if (y == 0)
        return x;
    ll c = x % y;
    while (c != 0) {
        x = y;
        y = c;
        c = x % y;
    }

    return y;

}

ll a, b, c;
ll ac, bd, x, y, xy, d;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> a >> b >> c >> d;
    if (a * d < b * c) {
        swap(a, b);
        swap(d, c);
    }

    x = b * c;
    y = d * a;
    ac = y - x;
    bd = gcd(ac, y);
    cout << ac / bd << "/" << y / bd << "\n";


    return 0;
}