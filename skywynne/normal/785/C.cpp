#include<bits/stdc++.h>
using namespace std;
long long n, m, l, r;
int Func(long long c)
{
    if (c - m >= sqrt(2e18))
    {
        return (1);
    }
    if ((c - m) * (c - m + 1) / 2 < n - m)
    {
        return (0);
    }
    return (1);
}
int main()
{
    cin >> n >> m;
    //n = 570441179141911871;
    //m = 511467058318039545;
    if (n <= m)
    {
        cout << n;
        return (0);
    }
    l = m;
    r = n + 1;
    while (r - l > 1)
    {
        if (Func((l + r) / 2) == 1)
        {
            r = (l + r) / 2;
        }
        else
        {
            l = (l + r) / 2;
        }
    }
    if ((l - m) * (l - m + 1) / 2 < n - m)
    {
        l ++;
    }
    cout << l;// << endl << Func(511467058661475480) << endl << Func(528053353170780177);
    return (0);
}