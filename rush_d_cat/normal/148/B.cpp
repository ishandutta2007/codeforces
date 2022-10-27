#include <iostream>
using namespace std;
const double EPS = 1e-7;
double vp, vd, t, f, c;

int main() {
    cin >> vp >> vd >> t >> f >> c;

    if(vd - vp <= 0) {
        printf("%d\n", 0); return 0;
    }

    double x = 0;
    int res = 0;
    x = vp * t;

    while(x + EPS < c) 
    {
        
        double dt = x / (vd - vp);
        x += dt * vp;

        if(x + EPS < c) {
            //cout << x << endl;
            res ++;
        }

        dt = x / vd;
        x += dt * vp;
        x += f * vp;

    }
    printf("%d\n", res);

}
// 1 2 1 1 10