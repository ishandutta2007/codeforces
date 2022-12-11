#include <iostream>

using namespace std;

int main()
{
    long long x=0, y=0, z=0, a, b, c, i, n;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        x = x + a;
        y = y + b;
        z = z + c;
    }

    if ((x == 0)&&(y == 0)&&(z == 0)) cout << "YES"; else cout << "NO";
    return 0;
}