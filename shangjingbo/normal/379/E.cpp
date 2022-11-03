#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define FOR(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++ i)

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;

const double EPS = 1e-8;
const double PI = acos(-1.0);


inline int sign(double x)
{
    return x < -EPS ? -1 : x > EPS;
}

struct Point
{
    double x, y;
    
    Point() {
    }
    
    Point(double x, double y) : x(x), y(y) {
    }
    
    double norm() const {
        return sqrt(x * x + y * y);
    }
};

Point operator + (const Point &a, const Point &b)
{
    return Point(a.x + b.x, a.y + b.y);
}

Point operator - (const Point &a, const Point &b)
{
    return Point(a.x - b.x, a.y - b.y);
}

Point operator * (const Point &a, const double &b)
{
    return Point(a.x * b, a.y * b);
}

Point operator / (const Point &a, const double &b)
{
    return Point(a.x / b, a.y / b);
}

double det(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

double dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}
//========================================================

const int maxn = 300 + 20;
const double INF = 1000;

Point sol[maxn], tmp[maxn];
int m;
int n, k, y[maxn][maxn];

double answer[maxn];

inline double getArea(Point a[], int n)
{
    a[n] = a[0];
    double sum = 0;
    for (int i = 0; i < n; ++ i) {
        sum += det(a[i], a[i + 1]);
    }
    return fabs(sum) / 2;
}

void rebuild(Point a, Point b)
{
    sol[m] = sol[0];
    int t = 0;
    for (int i = 1; i <= m; ++ i) {
        double k1 = det(b - a, sol[i] - a);
        double k2 = det(b - a, sol[i - 1] - a);
        if (sign(k1) * sign(k2) < 0) {
            tmp[t] = (sol[i] * k2 - sol[i - 1] * k1) / (k2 - k1);
            t ++;
        }
        if (sign(det(b - a, sol[i] - a)) >= 0) {
            tmp[t] = sol[i];
            t++;
        }
    }
    m = t;
    for (int i = 0; i < m; ++ i) {
        sol[i] = tmp[i];
    }
}


int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i) {
        for (int x = 0; x <= k; ++ x) {
            scanf("%d", &y[i][x]);
        }
        answer[i] = 0;
    }
    
    for (int x = 0; x < k; ++ x) {
        sol[0] = Point(x, 0);
        sol[1] = Point(x + 1, 0);
        sol[2] = Point(x + 1, INF);
        sol[3] = Point(x, INF);
        m = 4;
        
        double last = getArea(sol, m);
        for (int i = 0; i < n; ++ i) {
            rebuild(Point(x, y[i][x]), Point(x + 1, y[i][x + 1]));
            double cur = getArea(sol, m);
            answer[i] += fabs(cur - last);
            last = cur;
        }
    }
    
    for (int i = 0; i < n; ++ i) {
        printf("%.10f\n", answer[i]);
    }
    
    return 0;
}