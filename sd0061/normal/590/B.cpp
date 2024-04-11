#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
typedef long long LL;
const int N = 500005;
using namespace std;



int main() {
    double x1 , x2 , y1 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double dx = x2 - x1 , dy = y2 - y1;
    double len = sqrt(dx * dx + dy * dy);
    double V , T;
    cin >> V >> T;
    double ux , uy , wx , wy;
    cin >> ux >> uy;
    cin >> wx >> wy;

    double l = 0 , r = 1e10 , m;
    for (int i = 0 ; i < 200 ; ++ i) {
        m = (l + r) / 2;
        if (m <= T) {
            double x = dx - m * ux;
            double y = dy - m * uy;
            x /= m , y /= m;
            if (x * x + y * y <= V * V)
                r = m;
            else
                l = m;
        } else {
            double x = dx - T * ux + (T - m) * wx;
            double y = dy - T * uy + (T - m) * wy;
            x /= m , y /= m;
            if (x * x + y * y <= V * V)
                r = m;
            else
                l = m;            
        }
    }
    printf("%.10f\n" , r);
    return 0;
}