#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

typedef vector < int > vi;
typedef long long ll;

ll gcd(ll a, ll b)
{
    ll tmp = 0LL;
    while (b != 0LL)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

ll ans(ll a, ll b)
{
    ll res = 0LL;
    while (b != 0)
    {
        ll tmp = a / b, rev = a % b;
        res += tmp;
        a = b;
        b = rev;
    }
    return res;
}

int
main()
{
    ll a, b;
#ifdef _DEBUG
    while ((cin >> a >> b))
    {
#else
    cin >> a >> b;
#endif
    cout << ans(a, b) << endline;
#ifdef _DEBUG
    }
#endif
    return 0;
}