#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

const double eps = 1e-10 , pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    double x , y;
    Point (double x = 0 , double y = 0) : x(x) , y(y) {} 
    void input() {
        scanf("%lf%lf",&x,&y);
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
    Point operator * (const double& R) const{
        return Point(x * R , y * R);
    }
    Point operator / (const double& R) const{
        return Point(x / R , y / R);
    }
    double operator ^ (const Point& R) const{
        return x * R.y - y * R.x;
    }
    double operator % (const Point& R) const{
        return x * R.x + y * R.y;
    }
    double len() {
        return sqrt(*this % *this);
    }
};
double DistancePointToSegment(Point P , Point A , Point B) {
    if (A == B) return (P - A).len();
    Point v1 = B - A , v2 = P - A , v3 = P - B;
    if (dcmp(v1 % v2) < 0) return v2.len();
    if (dcmp(v1 % v3) > 0) return v3.len();
    return fabs(v1 ^ v2) / v1.len();
}

int n;
Point P , a[N];

void work() {
    scanf("%d" , &n);
    P.input();
    double mx = -1e60 , mn = 1e60;
    for (int i = 0 ; i < n ; ++ i) {
        a[i].input();
        a[i] = a[i] - P;
        mx = max(mx , a[i].len());
        mn = min(mn , a[i].len());      
    }
    a[n] = a[0];
    for (int i = 0 ; i < n ; ++ i) {
        double D = DistancePointToSegment(Point(0 , 0) , a[i] , a[i + 1]);
        mn = min(mn , D);
        mx = max(mx , D);        
    }
    printf("%.15f\n" , acos(-1.0) * (mx * mx - mn * mn));
}

int main() {    
    work();
    return 0;
}