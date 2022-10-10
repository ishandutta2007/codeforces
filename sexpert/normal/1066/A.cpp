#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int d, v, l, r;
        cin >> d >> v >> l >> r;
        int ans = d / v;
        ans -= r/v - (l - 1)/v;
        cout << ans << endl;
    }
}