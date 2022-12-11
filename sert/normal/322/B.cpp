#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, x, ans;
int a[10];

int main()
{
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a + 3);
    ans += a[0];
    for (int i = 2; i >= 0; i--)
        a[i] -= a[0];
    if (ans != 0 && a[1] % 3 + a[2] % 3 == 4)
        ans++;
    ans += a[1] / 3;
    ans += a[2] / 3;
    cout << ans;
    return 0;
}