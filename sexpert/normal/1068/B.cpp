#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long b;
    cin >> b;
    int ans = 0;
    for(long long d = 1; d * d <= b; d++)
    {
        if(b % d == 0) ans += 2;
        if(b == d*d) ans--;
    }
    cout << ans << endl;
}