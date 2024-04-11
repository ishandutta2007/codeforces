#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int R = 100000;
struct Point {
    int x , y;
    Point (int x = 0 , int y = 0) : x(x) , y(y) {}
    bool operator < (const Point& R) const {
        return make_pair(x , y) < make_pair(R.x , R.y);
    }
    Point operator - (const Point &R) const {
        return Point(x - R.x , y - R.y);
    }
    LL operator ^ (const Point &R) const {
        return (LL)x * R.y - (LL)y * R.x;
    }
    double len() {
        return sqrt(1.0 * x * x + 1.0 * y * y);
    }
}p[N] , s[N];

int n , m;
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x , y , v;
        scanf("%d%d%d" , &x , &y , &v);
        if (x >= v) {
            p[m ++] = Point(x - v , y);
        } else {
            p[m ++] = Point(0 , y - v + x);
            p[m ++] = Point(0 , y + v - x);
        }
        if (x + v <= R) {
            p[m ++] = Point(x + v , y);
        } else {
            p[m ++] = Point(R , y - v + R - x);
            p[m ++] = Point(R , y + v - R + x);
        }
        if (y >= v) {
            p[m ++] = Point(x , y - v);
        } else {
            p[m ++] = Point(x + v - y , 0);
            p[m ++] = Point(x - v + y , 0);            
        }
        if (y + v <= R) {
            p[m ++] = Point(x , y + v);
        } else {
            p[m ++] = Point(x - v + R - y , R);
            p[m ++] = Point(x + v - R + y , R);            
        }        
    }
    for (int i = 0 ; i < m ; ++ i) {
        p[i].x = min(R , max(0 , p[i].x));
        p[i].y = min(R , max(0 , p[i].y));        
    }
    sort(p , p + m);
    n = m , m = 0;
    for (int i = 0 ; i < n ; ++ i) {
        while (m > 1 && ((s[m - 1] - s[m - 2]) ^ (p[i] - s[m - 2])) <= 0)
            m --;
        s[m ++] = p[i];
    }
    int tmp = m;
    for (int i = n - 2 ; i >= 0 ; -- i) {
        while (m > tmp && ((s[m - 1] - s[m - 2]) ^ (p[i] - s[m - 2])) <= 0)
            m --;
        s[m ++] = p[i];
    }
    if (n > 1) -- m;
    double res = 0;
    Point ans[3];
    for (int i = 0 ; i < m ; ++ i) {
        Point X = s[i] , Y = s[(i + 1) % m] , Z = s[(i + 2) % m];
        double a = (X - Y).len() , b = (X - Z).len() , c = (Y - Z).len();
        double S = abs((Y - X) ^ (Z - X)) / 2.0 , R = a * b * c / 4 / S;
        if (R > res) {
            res = R;
            ans[0] = X , ans[1] = Y , ans[2] = Z;
        }
    }
    for (int i = 0 ; i < 3 ; ++ i)
        printf("%d %d\n" , ans[i].x , ans[i].y);
    return 0;
}