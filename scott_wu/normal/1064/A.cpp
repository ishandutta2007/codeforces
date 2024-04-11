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

int a[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> a[0] >> a[1] >> a[2];
    sort (a, a + 3);
    cout << max (0, a[2] + 1 - (a[0] + a[1])) << "\n";
}