#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int ans = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        ans += 12 * (i - 1);
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}