#include <iostream>

using namespace std;

int main()
{
    int n, xs = 0, ys = 0, zs = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        xs += x;
        ys += y;
        zs += z;
    }

    if (xs == 0 && ys == 0 && zs == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}