#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll x, y, z;
    cin >> x >> y >> z;
    ll maxcoconut = (x + y) / z;
    ll mingive;
    if (maxcoconut == x / z + y / z) mingive = 0;
    else mingive = min(z - x%z, z - y%z);
    cout << maxcoconut << ' ' << mingive;
    return 0;
}