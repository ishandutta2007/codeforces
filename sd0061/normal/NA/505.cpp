#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-10 , pi = acos(-1.0);
inline int dcmp(long double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    long double x , y;
    Point (long double x = 0 , long double y = 0) : x(x) , y(y) {}
    void input() {
        double xx , yy;
        scanf("%lf%lf",&xx,&yy);
        x = xx , y = yy;
    }
    bool operator < (const Point& R) const {
        if (dcmp(x - R.x) == 0)
            return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator == (const Point& R) const {
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
    }
    Point operator + (const Point& R) const {
        return Point(x + R.x , y + R.y);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y);
    }
    Point operator * (const long double& R) const {
        return Point(x * R , y * R);
    }
    Point operator / (const long double& R) const {
        return Point(x / R , y / R);
    }
    long double operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    long double operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    long double len() {
        return sqrt(*this % *this);
    }
    long double angle() {
        return atan2(y , x);
    }
};

vector<pair<long double, int>> StabPolygonLength(Point P, Point V, const Point *p, int np) {
    auto arg = [&P, &V](Point Q, Point W) {
        return (W ^ (P - Q)) / (V ^ W);
    };
    vector<pair<long double, int>> events;
    for (int i = 0 ; i < np ; ++ i) {
        int d0 = dcmp((p[i] - P) ^ V), d1 = dcmp((p[(i + 1) % np] - P) ^ V);
        if (d0 == d1) continue;
        long double t = arg(p[i] , p[(i + 1) % np] - p[i]);
        if (d0 < d1) {
            events.emplace_back(t , d0 && d1 ? 2 : 1);
        } else {
            events.emplace_back(t , d0 && d1 ? -2 : -1);
        }
    }
    sort(events.begin() , events.end());
    return events;
}

Point P[1000];
int n , m;

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i) {
        P[i].input();
    }
    while (m --) {
        Point A , B;
        A.input();
        B.input();
        vector<pair<long double, int>> E = StabPolygonLength(A , B - A , P , n);
        long double res = 0;
        for (int i = 0 , j = 0 ; i + 1 < E.size() ; ++ i) {
            j += E[i].second;
            if (j) res += E[i + 1].first - E[i].first;
        }
        printf("%.12Lf\n" , res * (B - A).len());
    }

}