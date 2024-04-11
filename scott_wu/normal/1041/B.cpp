#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcf (ll a, ll b)
{
    return ((b == 0) ? a : gcf (b, a % b));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll A, B, X, Y;
    cin >> A >> B >> X >> Y;
    ll g = gcf (X, Y);
    X /= g;
    Y /= g;

    cout << min (A / X, B / Y) << "\n";
}