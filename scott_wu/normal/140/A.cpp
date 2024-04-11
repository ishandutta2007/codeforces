#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979;
const double EPS = 1e-8;
int n, R, r;

int main()
{
    cin >> n >> R >> r;
    if (r > R)
    {
        cout << "NO\n";
        //system ("Pause");
        return 0;
    }
    if (n == 1)
    {
        cout << "YES\n";
        //system ("Pause");
        return 0;
    }
    int vr = R - r;
    double c = sqrt ((double)vr * vr * 2 - 2 * vr * vr * cos (2 * PI / n));
    if (c + EPS >= 2 * r)
        cout << "YES\n";
    else
        cout << "NO\n";
    //system ("Pause");
    return 0;
}