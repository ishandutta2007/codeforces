#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[5];

int main()
{
    for (int i = 0; i < 5; i++)
        num[i] = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        num[x]++;
    }
    int ans = num[4] + num[3];
    num[1] -= min (num[1], num[3]);
    ans += num[2] / 2;
    num[2] -= (num[2] / 2) * 2;
    num[1] += 2 * num[2];
    ans += (num[1] + 3) / 4;
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}