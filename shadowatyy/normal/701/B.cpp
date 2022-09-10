#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, x, y, ile_x, ile_y, res;

bitset<100007> Y;
bitset<100007> X;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    res = n*n;

    for(int i = 1; i <= m; ++i)
    {
        cin >> y >> x;

        if(!X[x] && !Y[y])
        {
            ++res;
        }

        if(!X[x])
        {
            res += ile_y;
            res -= n;
        }

        if(!Y[y])
        {
            res += ile_x;
            res -= n;
        }

        if(!X[x])
        {
            X[x] = 1;
            ++ile_x;
        }

         if(!Y[y])
        {
            Y[y] = 1;
            ++ile_y;
        }

        cout << res << endl;
    }
}