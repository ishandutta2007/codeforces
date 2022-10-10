#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    for(int tc = 0; tc < q; ++tc)
    {
        long long x, y;
        cin >> x >> y;
        if((x + y)%2 == 0)
        {
            cout << ((x - 1ll)*n + y + 1)/2ll;
        } else
        {
            cout << (n*n + 1ll)/2ll + ((x - 1ll)*n + y + 1)/2ll;
        }
        cout << endl;
    }
}