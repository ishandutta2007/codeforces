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

    int x, y, z;
    cin >> x >> y >> z;
    y--;
    z -= 2;
    int m = min (min (x, y), z);
    cout << m * 3 + 3 << "\n";
}