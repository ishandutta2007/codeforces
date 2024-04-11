#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
const int MAXN = 110;

int n;
int a[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    int ans = 0, penalty = 0, curt = 10, loc = 0;
    while (curt <= 720 && loc < n)
    {
        curt += a[loc];
        if (curt <= 720)
        {
            ans++;
            if (curt >= 360)
                penalty += curt - 360;
            loc++;
        }
        else
            break;
    }
    cout << ans << " " << penalty << "\n";
    //system ("Pause");
    return 0;
}