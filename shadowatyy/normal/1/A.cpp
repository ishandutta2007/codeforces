#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll n, m, a, res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> a;

    if(n%a)
    {
        res = n/a+1;
    }
    else
    {
        res = n/a;
    }

    if(m%a)
    {
        res *= m/a+1;
    }
    else
    {
        res *= m/a;
    }

    cout << res;
}