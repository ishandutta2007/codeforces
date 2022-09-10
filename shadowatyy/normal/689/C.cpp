#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

ll m, l = 1, r = 8000000000000000000, s;

ll sprawdz(ll a)
{
    ll res = 0;

    for(ll i = 2;; ++i)
    {
        res += a/(i*i*i);

        if(a/(i*i*i)==0)
        {
            return res;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> m;

    while(l<r-2)
    {
        s = (l+r+1)/2;

        if(sprawdz(s)<m)
        {
            l = s;
        }
        else
        {
            r = s;
        }
    }

    for(ll k = l; k <= r; ++k)
    {
        if(sprawdz(k)==m)
        {
            while(sprawdz(k-1)==m)
            {
                k--;
            }

            cout << k;
            return 0;
        }
    }

    cout << -1;
}