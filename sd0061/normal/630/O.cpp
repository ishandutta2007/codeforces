#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 100005;

struct Point {
    double x , y;
    Point (double _x = 0 , double _y = 0) {
        x = _x , y = _y;
    }
    void print() {
        printf("%.15f %.15f\n" , x , y);
    }
    Point operator + (const Point& R) const{
        return Point(x + R.x , y + R.y);
    }
    Point operator - (const Point& R) const{
        return Point(x - R.x , y - R.y);
    }
    Point operator * (const double& R) const{
        return Point(x * R , y * R);
    }
};
Point P , Vy , Vx;
int main() {
    double a , b , c , d;
    cin >> P.x >> P.y >> Vy.x >> Vy.y >> a >> b >> c >> d;
    double len = sqrt(Vy.x * Vy.x + Vy.y * Vy.y);
    Vy.x /= len , Vy.y /= len;
    Vx = Point(Vy.y , -Vy.x);
    
    (P + Vy * b).print();
    (P - Vx * (a / 2)).print();
    (P - Vx * (c / 2)).print();
    (P - Vx * (c / 2) - Vy * d).print();
    (P + Vx * (c / 2) - Vy * d).print();
    (P + Vx * (c / 2)).print();
    (P + Vx * (a / 2)).print();        
    return 0;
}