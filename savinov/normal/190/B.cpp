#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int x1,y1,r1,x2,y2,r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>(r1+r2)*(r1+r2))
    {
        cout << fixed;
        cout << setprecision(9) << (sqrt((long double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))-(long double) (r1+r2))*0.5L;
        return 0;
    }
    if (sqrt((long double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))+(long double)r1<(long double)r2)
    {
        cout << fixed;
        cout << setprecision(9) << -0.5L*(sqrt((long double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))+(long double)r1-(long double)r2);
        return 0;
    }
    if (sqrt((long double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))+(long double)r2<(long double)r1)
    {
        cout << fixed;
        cout << setprecision(9) << -0.5L*(sqrt((long double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))+(long double)r2-(long double)r1);
        return 0;
    }
    cout << "0\n";
    return 0;
}