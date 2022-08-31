#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x, y, z;
    x = (a + 1) / 2, y = (b + 1) / 2, z = (c + 1) / 2;
    cout << max (max (3 * x, 3* y + 1), 3 * z + 2) + 27 << "\n";
    return 0;
    }