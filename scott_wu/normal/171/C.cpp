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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        ans += t * (i + 1);
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}