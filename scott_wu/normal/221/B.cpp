#include <iostream>

using namespace std;

int val (int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans |= (1 << (x % 10));
        x /= 10;
    }
    return ans;
}

int main()
{
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 1; i <= x; i++)
    {
        if (i * i > x)
            break;
        if (x % i != 0)
            continue;
        if (val (x) & val (i))
            ans++;
        if (i * i != x && val (x) & val (x / i))
            ans++;
    }
    cout << ans << "\n";
    return 0;
}