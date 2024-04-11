#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
const double EPS = 1e-9;

double a, b, m, vx, vy, vz;

int main()
{
    cout << fixed << setprecision (7);
    cin >> a >> b >> m >> vx >> vy >> vz;
    double ex = (-m / vy) * vx + (a / 2.0);
    double ez = (-m / vy) * vz;
    while (ex < -EPS)
        ex += 2 * a;
    while (ex > 2 * a + EPS)
        ex -= 2 * a;
    if (ex > a)
        ex = 2 * a - ex;
    
    while (ez < -EPS)
        ez += 2 * b;
    while (ez > 2 * b + EPS)
        ez -= 2 * b;
    if (ez > b)
        ez = 2 * b - ez;
    
    cout << ex << " " << ez << "\n";
    //system ("Pause");
    return 0;
}