#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long a, b, k;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> k;
        long long d = a - b;
        long long ans = (k / 2)*d + (k % 2)*a;
        cout << ans << endl;
    }
}