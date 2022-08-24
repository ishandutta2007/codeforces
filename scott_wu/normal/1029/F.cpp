#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

ll A, B;

int main()
{
    cin >> A >> B;
    ll C = A + B;
    ll bbest = 1e18;
    ll res = 1e18;
    for (int i = 1; i < 15000000; i++)
    {
        if (A % i == 0)
        {
            bbest = min (bbest, A / i);
        }
        if (B % i == 0)
        {
            bbest = min (bbest, B / i);
        }

        if (C % i == 0)
        {
            if (bbest <= C / i)
                res = min (res, 2 * (i + (C / i)));
        }
    }
    cout << res << "\n";
}