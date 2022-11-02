#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
int n, t, a, b, c, d, l, r, x, y;
vector < int > V;
int32_t main()
{
    cin >> l >> r >> x  >> y;
    n = x * y;
    for (int i = 1; i <= sqrt(y); i++)
    {
        if (y % i == 0)
        {
            V.pb(i);
            if (i * i != y)
                V.pb(y / i);
        }
    }
    for (auto X : V)
    {
        a = n / X;
        if (l <= X && X <= r && l <= a && a <= r && __gcd(a, X) == x)
            c ++;
    }
    cout << c;
    return (0);
}