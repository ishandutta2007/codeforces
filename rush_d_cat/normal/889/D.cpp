#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 2002;
const double EPS = 1e-7;
double d[N];
int vis[N];



struct Point {
    double x, y;
    Point(){}
    Point(double x_, double y_) {
        x = x_;
        y = y_;
    }
    void read() {
        scanf("%lf %lf", &x, &y);
    }
    void print() {
        printf("%.5f %.5f\n", x, y);
    }
    Point operator + (const Point &other) const {
        return Point(x+other.x, y+other.y);
    }
    Point operator - (const Point &other) const {
        return Point(x-other.x, y-other.y);
    }
    Point operator / (const double &val) const {
        return Point(x/val, y/val);
    }
    double operator * (const Point &other) const{
        return x*other.x + y*other.y; 
    }
    double operator ^ (const Point &other) const {
        return x * other.y - y * other.x;
    }

} p[N];

struct Line
{   
    Point start, direct;
    Line() {}
    Line(Point start_, Point direct_) {
        start = start_;
        direct = direct_; 
    } 
    double dis(Point P) {
        return (direct ^ (P - start)) / sqrt(direct * direct);
    }
    bool same(Line L) {
        if (abs(direct ^ L.direct) > EPS) return 0;
        if (abs(direct ^ (L.start - start)) > EPS) return 0;
        return 1;
    }
} l[N]; int cnt = 0;

int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) 
        p[i].read();

    if (n <= 2) {
        printf("-1\n"); return 0;
    }

    if (p[1]*p[1] < EPS) 
        swap(p[1], p[2]);
    
    Point M(0, 0);
    for (int i = 1; i <= n; i ++) 
        M = M + p[i];
    M = M / n;
    
    //M.print();

    int sym = 0, pos;
    for (int i = 1; i <= n; i ++) {
        int flag = 0;
        for (int j = 1; j <= n; j ++) {
            if ((p[j]+p[i])*(p[j]+p[i])<EPS || ((p[j]+p[i])/2-M)*((p[j]+p[i])/2-M)<EPS) 
                flag = 1;
        }
        if (flag) sym ++;
        else pos = i;
    }



    if (sym == n) {
        printf("%d\n", -1);
        return 0;
    }

    swap(p[1], p[pos]);


    for (int i = 1; i <= n; i ++) {
        if ((p[1]+p[i])*(p[1]+p[i])<EPS)
            continue;

        if (((p[1]+p[i])/2-M)*((p[1]+p[i])/2-M)<EPS)
            continue;

        Point P = (p[1] + p[i]) / 2;
        Line L = Line(P, P - M);
        for (int j = 1; j <= n; j ++) {
            d[j] = L.dis(p[j]);
        }
    
        sort(d+1, d+1+n);
        /*
        printf("%d\n", i);
        for (int i = 1; i <= n; i ++) {
            printf("%.5f ", d[i]);
        }
        printf("\n");
        */
        bool ok = 1;
        for (int i = 1; i <= n; i ++) {
            if (d[i] + d[n+1-i] > EPS) {
                ok = 0; break;
            }
        }
        if (ok) l[++cnt] = L;
    }

    //printf("%d\n", cnt);
    int ans = 0;
    for (int i = 1; i <= cnt; i ++) {
        int flag = 1;
        for (int j = 1; j < i; j ++) {
            if (l[i].same(l[j])) flag = 0;
        }
        if (flag) ans ++; 
    }
    printf("%d\n", ans);

}