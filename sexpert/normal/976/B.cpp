#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    m--;
    if(k < n) cout << k + 1 << " " << 1;
    else
    {
        long long p = k - n;
        long long x;
        if(p%(2*m) < m) x = p%(2*m);
        else x = 2*m - 1 - p%(2*m);
        cout << n - p/m << " " << x + 2;
    }
}