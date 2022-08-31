#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

int N, K;
ll lo, hi;

ll gcf (ll x, ll y)
{
    if (y == 0) return x;
    return gcf (y, x % y);
}

void run (ll x)
{
    x %= K;
    if (x <= 0) x += K;
    ll p = N * (ll) K;
    while (x <= p)
    {
        ll g = gcf (x, p);
        lo = min (lo, p / g);
        hi = max (hi, p / g);
        x += K;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    int A, B;
    cin >> A >> B;
    lo = 1e11;
    hi = 0;

    run (A + B);
    run (A - B);
    run (B - A);
    run (-B - A);
    cout << lo << " " << hi << "\n";
}