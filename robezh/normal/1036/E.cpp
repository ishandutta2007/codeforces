#include<bits/stdc++.h>
using namespace std;

#define long double double

int n;
const int N = 1005;
const double EPS = 1e-7;


struct point {
    double x,y;
    point() {
        x = 0;
        y =0;
    }
    point(double x1, double y1) {
        x = x1;
        y = y1;
    }
    bool operator == (point other) const{
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
    bool operator < (point other) const{
        return fabs(x - other.x) < EPS ? (fabs(y - other.y) < EPS ? false : y < other.y) : x < other.x;
    }
};

point a[N], b[N];


double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line {
    double a,b,c;


};

int gcd(int x, int y){
    if(x == 0) return y;
    if(y == 0) return x;
    return __gcd(x, y);
}

line pointsToLine(point p1, point p2) {
    line l;
    if(fabs(p1.x - p2.x) < EPS) {
        l.a = 1;
        l.b = 0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}

bool areParrelel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areIntersect(point a1, point a2, point b1, point b2, point &p) {
    line l1 = pointsToLine(a1, a2);
    line l2 = pointsToLine(b1, b2);
    if(areParrelel(l1,l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(p.x < min(a1.x,a2.x) - EPS || p.x > max(a1.x,a2.x) + EPS
       || p.x < min(b1.x,b2.x) - EPS || p.x > max(b1.x,b2.x) + EPS) {
        return false;
    }
    if(fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);

    if(fabs(floor(p.x + EPS) - p.x) > EPS) return false;
    if(fabs(floor(p.y + EPS) - p.y) > EPS) return false;
    if(p.y < min(a1.y,a2.y) - EPS || p.y > max(a1.y,a2.y) + EPS) return false;
    if(p.y < min(b1.y,b2.y) - EPS || p.y > max(b1.y,b2.y) + EPS)  return false;

    return true;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += abs(gcd((int)(a[i].x - b[i].x), (int)(a[i].y - b[i].y))) + 1;
        vector<point> pts;
        for(int j = 0; j < i; j++){
            point now;
            if(areIntersect(a[i], b[i], a[j], b[j], now)){
                pts.push_back(now);
            }
        }
        sort(pts.begin(), pts.end());
        res -= unique(pts.begin(), pts.end()) - pts.begin();
    }
    cout << res << endl;
}