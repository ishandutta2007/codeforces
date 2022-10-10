#include <bits/stdc++.h>
using namespace std;
typedef double ld;

const ld INF = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1);

struct pt {
    ld x, y;
    pt(ld x = 0, ld y = 0) : x(x), y(y) {}
    pt operator+(pt o) { return pt(x + o.x, y + o.y); }
    pt operator-(pt o) { return pt(x - o.x, y - o.y); }
    pt operator*(ld c) { return pt(c*x, c*y); }
    ld normsq() { return x*x + y*y; }
    ld norm() { return hypot(x, y); }
};

ld dot(pt p1, pt p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

ld dist(pt p1, pt p2) {
    return (p1 - p2).norm();
}

pt proj(pt x, pt p1, pt p2) {
    pt u = p2 - p1;
    ld t = dot(x - p1, u)/u.normsq();
    return p1 + u*t;
}

ld dist(pt x, vector<pt> &P) {
    ld ans = INF;
    for(pt p : P)
        ans = min(ans, dist(x, p));
    for(int i = 0; i < P.size(); i++) {
        pt p1 = P[i], p2 = P[(i + 1) % P.size()];
        pt foot = proj(x, p1, p2);
        //cout << x.x << " " << x.y <<  " " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << foot.x << " " << foot.y << endl;
        if(abs(dist(p1, foot) + dist(foot, p2) - dist(p1, p2)) < EPS)
            ans = min(ans, dist(x, foot)); 
    }
    return ans;
}

ld mx(pt x, vector<pt> &P) {
    ld ans = 0;
    for(pt p : P)
        ans = max(ans, dist(x, p));
    return ans;
}

int main() {
    int n;
    ld x, y;
    cin >> n >> x >> y;
    pt pos {x, y};
    vector<pt> poly(n);
    for(int i = 0; i < n; i++) {
        ld x, y;
        cin >> x >> y;
        poly[i] = pt{x, y};
    }
    ld R = mx(pos, poly), r = dist(pos, poly);
    cout << fixed << setprecision(20) << PI*(R*R - r*r) << endl;
}