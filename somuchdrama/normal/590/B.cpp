#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int ITER = 1e5;

struct point{
    double x, y;
    point(){}
    point(double x, double y): x(x), y(y){}
};

point input() {
    double a, b;
    cin >> a >> b;
    return point(a, b);
}

double dist(point a, point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}


int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    point s, f;
    s = input()    ;
    f = input();

    double v, t, vx, vy, wx, wy;
    cin >> v >> t >> vx >> vy >> wx >> wy;

    double l = 0, r = 1e9;

    for (int it = 0; it < ITER; ++it) {
        double m = (l + r) * 0.5;
        point s2 = s;   
        if (m > t) {
            s2.x += vx * t;
            s2.y += vy * t;
            s2.x += wx * (m - t);
            s2.y += wy * (m - t);
        } else {
            s2.x += vx * m;
            s2.y += vy * m;
        }
        if (dist(s2, f) <= v * m)
            r = m;
        else
            l = m;
    }

    cout << r << '\n';
       

    return 0;
}