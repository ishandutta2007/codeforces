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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int stair = abs (x - y) * t1;
    int elev = abs (x - z) * t2 + t3 + t3 + abs (x - y) * t2 + t3;

    if (elev <= stair)
        cout << "YES\n";
    else
        cout << "NO\n";
}