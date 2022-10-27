#include <iostream>
#include <cmath>
using namespace std;
const double EPS = 1e-9;

double y_1, y2, yw, xb, yb, r;

int main() 
{
    cin >> y_1 >> y2 >> yw >> xb >> yb >> r;

    double A = (yw - r) - (y_1 + r);
    double B = A + (yw - r - yb);

    double Px = xb * A / B;
    double Py = yw - r;
    double sink = Px / sqrt(Px * Px + A * A);
    double LEN = ( y2 - (y_1 + r) ) * sink;

    if (LEN < r + EPS) printf("-1\n");
    else printf("%.9f\n", Px);
}