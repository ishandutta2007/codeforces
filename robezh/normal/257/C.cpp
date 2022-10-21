#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926535;
double ang[100050];

int main(){
    int n;
    double x,y;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf%lf", &x, &y);
        double angle = acos(x / hypot(x,y)) / PI * 180;
        if(y < 0) angle = 360 - angle;
        ang[i] = angle;
    }
    sort(ang, ang+n);
    double large = 360 - ang[n-1] + ang[0];
    for(int i = 1; i < n; i++) large = max(large, ang[i]-ang[i-1]);
    cout << fixed << setprecision(10) << (360-large) << endl;
}