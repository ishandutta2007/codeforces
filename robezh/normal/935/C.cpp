#include <bits/stdc++.h>
using namespace std;

double R,a1,b1,a2,b2;
double c1,d1;


int main(){
    cin >> R >> a1 >> b1 >> a2 >> b2;

//    if(a1 == a2 && b1 == b2){
//
//    }

    a2 -= a1, b2 -= b1;

    if(sqrt(a2 * a2 + b2 * b2) > R){
        cout << fixed << setprecision(10) << a1 << " " << b1 << " " << R;
        return 0;
    }

    if(a2 == 0 && b2 == 0){
        double x, y;
        x = y = sqrt(R*R/8);
        x += a1, y += b1;
        cout << fixed << setprecision(10) << x << " " << y << " " << R/2;
        return 0;
    }

    double r = R - (R - sqrt(a2 * a2 + b2 * b2)) / 2;
    double Rl = (R - sqrt(a2 * a2 + b2 * b2)) / 2;
    c1 = -a2 / sqrt(a2 * a2 + b2 * b2) * (r - sqrt(a2 * a2 + b2 * b2)) + a1;
    d1 = -b2 / sqrt(a2 * a2 + b2 * b2) * (r - sqrt(a2 * a2 + b2 * b2)) + b1;

    cout << fixed << setprecision(10) << c1 << " " << d1 << " " << r;

}