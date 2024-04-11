#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1005;

struct Point {
    int x , y;
    Point () {}
    Point (int _x , int _y) {
        x = _x , y = _y;
    }
    inline void input() {
        scanf("%d%d",&x,&y);
    }
    Point operator + (const Point& R) const {
        return Point(x + R.x , y + R.y);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y);
    }
    int operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    int operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    int len() {
        return x * x + y * y;
    }
};
int n , m , R;
Point P , a[N] , Q , b[N];

LL DistancePointToSegment(Point P , Point A , Point B) {
    Point v1 = B - A , v2 = P - A , v3 = P - B;
    if ((v1 % v2) < 0) return (LL)v1.len() * v2.len();
    if ((v1 % v3) > 0) return (LL)v1.len() * v3.len();
    return (LL)(v1 ^ v2) * (v1 ^ v2);
}

bool check() {
    for (int i = 0 ; i < n ; ++ i) {
        Point O = Q + a[i] - P;
        for (int j = 0 ; j < m ; ++ j) {
            Point A = b[j] , B = b[j + 1];
            int t = ((A - O).len() < R) + ((B - O).len() < R);
            if (t == 1)
                return 1;
            if (t == 2)
                continue;
            long long c = DistancePointToSegment(O , A , B);
            if (c <= (long long) R * (B - A).len())
                return 1;
        }
    }
    return 0;
}

void work() {
    P.input();
    scanf("%d",&n);
    for (int i = 0 ; i < n ; ++ i)
        a[i].input();
    a[n] = a[0];
    Q.input();
    scanf("%d",&m);
    for (int i = 0 ; i < m ; ++ i)
        b[i].input();
    b[m] = b[0];
    R = (P - Q).len();
    if (check()) {
        puts("YES");
        return;
    }
    swap(n , m);
    swap(P , Q);
    swap(a , b);
    if (check()) {
        puts("YES");
        return;
    }
    puts("NO");
}

int main() {
    work();
    return 0;
}