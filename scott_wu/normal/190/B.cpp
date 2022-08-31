#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
double x, y, r, x2, y2, r2;
cin >> x >> y >> r >> x2 >> y2 >> r2;
cout << fixed << setprecision (7);
double dist = sqrt ((x2-x)*(x2-x)+(y2-y)*(y2-y));
if (dist + r >= r2 && dist + r2 >= r && dist < r + r2)
cout << "0\n";
else if (dist >= r + r2)
cout << (dist - r - r2) / 2 << "\n";
else
cout << (max (r, r2) - min (r, r2) - dist) / 2 << "\n";
return 0;
}