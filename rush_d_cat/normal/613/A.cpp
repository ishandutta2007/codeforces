#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int NICO = 100002;
int n;
double px, py, x[NICO], y[NICO];
double mn = 1e9, mx = 0;

struct Point  
{  
    LL x, y;  
    Point() {}  
    Point(int x_, int y_) { x = x_; y = y_; }  
    Point operator - (const Point& b)const  
    {  
        return Point(x - b.x, y - b.y);  
    }  
};  
  
//  
double Dot(Point& a,Point& b)  
{  
    return a.x*b.x + a.y*b.y;  
}  
//  
double Len(Point a)  
{  
    return sqrt(a.x*a.x + a.y*a.y);  
}  
//  
double Dis(Point& a,Point& b)  
{  
    return Len(Point(a - b));  
}  
//abc  
double Point_To_Segment(Point& a,Point& b,Point& c)  
{  
    Point x = a - b;  
    Point y = c - b;  
    Point z = c - a;  
    if (Dot(x, y) < 0)return Len(x);  
    if (Dot(y, z) < 0)return Len(z);  
    return fabs((x.x*y.y - x.y*y.x) / Len(y));  
}  

int main() {
    scanf("%d %lf %lf", &n, &px, &py);
    for(int i = 1; i <= n; i ++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    for(int i = 1; i <= n; i ++) {
        
        if(i == n) x[n+1] = x[1], y[n+1] = y[1];

        double dis = sqrt( (x[i]-px)*(x[i]-px) + (y[i]-py)*(y[i]-py) );
        mn = min(mn, dis);
        mx = max(mx, dis);

        Point A = Point(x[i+1], y[i+1]);
        Point B = Point(x[i], y[i]);
        Point P = Point(px, py);

        double dis_to_seg = Point_To_Segment(P, A, B);
        //printf("%.7f\n", dis_to_seg);
        mn = min(mn, dis_to_seg);
        
    }
    double ans = acos(-1) * (mx*mx - mn*mn);
    printf("%.8f\n", ans);
}