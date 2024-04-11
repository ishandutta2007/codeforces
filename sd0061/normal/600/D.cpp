#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200005;

const long double eps = 1e-12 , pi = acos(-1.0);
inline int dcmp(long double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    long double x , y;
    Point (long double x = 0 , long double y = 0) : x(x) , y(y) {} 
    void input() {
        double X , Y;       
        scanf("%lf%lf",&X,&Y);
        x = X , y = Y;
    }
    bool operator < (const Point& R) const{
        if (dcmp(x - R.x) == 0)
            return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator == (const Point& R) const{
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
    }
    Point operator + (const Point& R) const{
        return Point(x + R.x , y + R.y);
    }
    Point operator - (const Point& R) const{
        return Point(x - R.x , y - R.y);
    }
    Point operator * (const long double& R) const{
        return Point(x * R , y * R);
    }
    Point operator / (const long double& R) const{
        return Point(x / R , y / R);
    }
    long double operator ^ (const Point& R) const{
        return x * R.y - y * R.x;
    }
    long double operator % (const Point& R) const{
        return x * R.x + y * R.y;
    }
    long double len() {
        return sqrt(*this % *this);
    }
};
long double Angle(Point V) {
    return atan2(V.y , V.x);
}
long double Angle(Point A , Point B) {
    return acos((A % B) / A.len() / B.len());
}
struct Circle {
    Point O;
    long double r;
    Circle () {}
    Circle (Point _O , long double _r) {O = _O , r = _r;}
    Point point(long double arc) {
        return Point(O.x + cos(arc) * r , O.y + sin(arc) * r);
    }
    void input() {
        O.input() ;
        double R;
        scanf("%lf",&R);
        r = R;
    }
};
long double getCircleCircleIntersection(Circle C1 , Circle C2) {
    long double d = (C1.O - C2.O).len();
    if (dcmp(C1.r + C2.r - d) < 0) return 0;
    if (dcmp(fabs(C1.r - C2.r) - d) > 0) return pi * C2.r * C2.r;
    
    long double p , da , res = 0;

    p = (C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d);
    //p = max(-1.0 , min(1.0 , p));
    da = acos(p) * 2;
    res += C1.r * C1.r * (da - sin(da)) / 2;

    swap(C1 , C2);
    
    p = (C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d);
    //p = max(-1.0 , min(1.0 , p));
    da = acos(p) * 2;
    res += C1.r * C1.r * (da - sin(da)) / 2;

    return res;
}
void work() {
    Circle A , B;
    A.input();
    B.input();

    if (A.r < B.r)
        swap(A , B);

    if (A.O == B.O) {
        printf("%.15f\n" , (double)(pi * B.r * B.r));
    } else {
        printf("%.15f\n" , (double)getCircleCircleIntersection(A , B));    
    }
    
}

int main() {
    work();
    return 0;
}