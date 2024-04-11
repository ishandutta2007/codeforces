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
    long double x , y;
    Point (long double _x = 0 , long double _y = 0) {
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
    Point operator * (const long double& R) const{
        return Point(x * R , y * R);
    }
    long double operator ^ (const Point& R) const{
        return x * R.y - y * R.x;
    }
};
Point GetLineIntersection(Point P , Point v , Point Q , Point w) {
    Point u = P - Q;
    long double t1 = (w ^ u) / (v ^ w);
    return P + v * t1;
}
Point Rotate(Point A , long double rad) {
    long double Sin = sin(rad) , Cos = cos(rad);
    return Point(A.x * Cos - A.y * Sin , A.x * Sin + A.y * Cos);
}
int main() {
    int n , L;
    cin >> n >> L;
    long double beta = 2 * acos(-1) / n; 
    long double arc = beta * ((n - 1) / 2);
    Point O , A , B , C , D;
    O = Point(L , 0);
    A = Rotate(O , beta);
    B = Rotate(O , -arc);
    C = Rotate(O , -beta);
    D = Rotate(O , arc);
    Point P = GetLineIntersection(A , B - A , C , D - C);
    long double res = 0;
    res += (D ^ P) + (P ^ B);
    res /= 2;
    res = res * n;
    printf("%.20f\n" , (double)res);
    return 0;
}