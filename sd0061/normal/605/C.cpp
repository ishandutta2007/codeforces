#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

struct Point {
    int x , y;
    Point (int _x = 0 , int _y = 0) {
        x = _x , y = _y;
    }
    bool operator < (const Point& R) const{
        if (x != R.x)
            return x < R.x;
        return y < R.y;
    }
    Point operator + (const Point& R) const{
        return Point(x + R.x , y + R.y);
    }
    Point operator - (const Point& R) const{
        return Point(x - R.x , y - R.y);
    }
    LL operator ^ (const Point& R) const{
        return (LL)x * R.y - (LL)y * R.x;
    }
};
double GetLineIntersection(Point P , Point v , Point Q , Point w) {
    Point u = P - Q;
    return 1.0 * (w ^ u) / (v ^ w);
}
int n , A , B;
Point p[N] , q[N] , s[N];
double res;
int main() {
    res = 1e60;
    scanf("%d%d%d" , &n , &A , &B);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &p[i].x , &p[i].y);
        res = min(res , max(1.0 * A / p[i].x , 1.0 * B / p[i].y));
    }
    sort(p , p + n);
    int m = 0;
    for (int i = 0 ; i < n ; ++ i) {
        while (m && p[i].y >= q[m - 1].y)
            -- m;
        q[m ++] = p[i];
    }
    n = 0;
    for (int i = 0 ; i < m ; ++ i) {
        while (n > 1 && ((s[n - 1] - s[n - 2]) ^ (q[i] - s[n - 2])) >= 0)
            n --;
        s[n ++] = q[i];
    }
    for (int i = 1 ; i < n ; ++ i) {
        double t0 = GetLineIntersection(Point(0 , 0) , Point(A , B) , s[i - 1] , s[i] - s[i - 1]);
        double t1 = GetLineIntersection(s[i - 1] , s[i] - s[i - 1] , Point(0 , 0) , Point(A , B));
        if (t0 >= 0 && t1 >= -1e-8 && t1 - 1e-8 <= 1) {
            res = min(res , 1.0 / t0);
        }
    }
    printf("%.15f\n" , res);
    return 0;
}