#include <iostream>

using namespace std;
typedef long long ll;
const int HI = 1000000000;

int ndig (ll a)
{
    if (a == 0) return 1;
    int ans = 0;
    while (a > 0)
    {
        ans++;
        a /= 10;
    }
    return ans;
}

int main()
{
    ll a, b, m;
    cin >> a >> b >> m;
    for (ll i = 1; i < min (a + 1, m); i++)
    {
        if ((i * HI - 1) / m == (i * HI + b) / m)
        {
            cout << "1 ";
            for (int j = 0; j < 9 - ndig (i); j++)
                cout << 0;
            cout << i << "\n";
            //system ("Pause");
            return 0;
        }
    }
    cout << "2\n";
    //system ("Pause");
    return 0;
}