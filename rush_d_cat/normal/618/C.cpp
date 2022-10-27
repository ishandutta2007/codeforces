#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point {
    double x,y;
    Point(double x=0, double y=0):x(x),y(y) {}
};

typedef Point Vector;
Point operator + (Point A, Point B) {return Point(A.x+B.x,A.y+B.y);}
Point operator - (Point A, Point B) {return Point(A.x-B.x,A.y-B.y);}
Point operator * (Point A, double p){return Point(p*A.x,p*A.y);}
Point operator / (Point A, double p){return Point(A.x/p, A.y/p);}
bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);    
}
const double EPS = 1e-7;
int dcmp(double x) {
    if(fabs(x) < EPS) return 0; else return x<0?-1:1;
}
bool operator == (const Point& a, const Point &b) {
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}
double Dot(Point A, Point B) { return A.x*B.x + A.y*B.y; }
double Length(Point A) { return sqrt(Dot(A, A)); }
double Angel(Point A, Point B) { 
    return acos(Dot(A, B) / Length(A) / Length(B));
}
double Cross(Point A, Point B) {return A.x*B.y - A.y*B.x;}
double Area2(Point A, Point B, Point C) {return Cross(B-A,C-A);}
Point Rotate(Point A, double rad) {
    return Point(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
Point Normal(Point A) {
    double L = Length(A);
    return Point(-A.y/L, A.x/L);
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P-Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v*t;
}
double DistanceToLine(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2) / Length(v1));
}
double DistanceToSegment(Point P, Point A, Point B) {
    if(A == B) return Length(P-A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}
bool OnSegment(Point p, Point a1, Point a2) {
    return dcmp(Cross(a1-p,a2-p))==0 && dcmp(Dot(a1-p, a2-p)) < 0;
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1,b2-a1);
    double c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}


int n;
double x[100000+10], y[100000+10];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    Point A(x[1], y[1]); Point B(x[2], y[2]);
    int nm = 2; double s = 1e16;

    for(int i = 2; i <= n; i ++) {
        double tmp = sqrt((x[1] - x[i]) * (x[1] - x[i]) + (y[1] - y[i]) * (y[1] - y[i]));
        if(dcmp(s - tmp) == 1) s = tmp, nm = i;
    }

    int id = 2; double dis = 1e16;
    for(int i = 2; i <= n; i ++) {
        if(i == nm) continue;

        double tmp = DistanceToLine(Point(x[i], y[i]), A, Point(x[nm], y[nm]));
        if(dcmp(tmp) == 1 && dcmp(dis - tmp) == 1) id = i, dis = tmp; 
    }
    
    printf("%d %d %d\n", 1, nm, id);
}