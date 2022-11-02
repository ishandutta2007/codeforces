#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;
const double eps = 1e-9;

struct P {
    double x, y;
    bool operator<(const P &p) const { return (x != p.x ? x < p.x : y < p.y); }
    bool operator==(const P &p) const { return x == p.x && y == p.y; }
    P() : x(0), y(0) { }
    P(double x, double y) : x(x), y(y) { }
};
P operator-(P a, P b) {
    return P(a.x-b.x, a.y-b.y);
}
double operator^(P a, P b) {
    return a.x*b.y - a.y*b.x;
}
bool left(P a, P b, P c) {
    return ((b-a)^(c-a)) > eps;
}
bool right(P a, P b, P c) {
    return ((b-a)^(c-a)) < -eps;
}

int N;
double X, Y, ans;
P p[MaxN];
std::vector<P> q;

int main()
{
    scanf("%d%lf%lf", &N, &X, &Y);
    for (int i = 0; i < N; i++) scanf("%lf%lf", &p[i].x, &p[i].y);

    std::sort(p, p+N);
    for (int i = 0; i < N; i++) {
        if (i && p[i] == p[i-1]) continue;
        while (sz(q) >= 2) {
            int k = sz(q);
            P a = q[k-2], b = q[k-1], c = p[i];
            if (!right(a, b, c)) q.pop_back();
            else break;
        }
        if (sz(q) == 1 && p[i].y > q[0].y) q.pop_back();
        q.push_back(p[i]);
    }
    
    P o(0, 0), t(X, Y);
    if (!left(o, q.back(), t)) ans = X / q.back().x;
    else if (!right(o, q[0], t)) ans = Y / q[0].y;
    else {
        int i = 0;
        while (!left(o, q[i+1], t)) i++;
        double x1 = q[i].x, y1 = q[i].y;
        double x2 = q[i+1].x, y2 = q[i+1].y;
        double b = (x1*Y - X*y1) / (x1*y2 - x2*y1);
        double a = (X - b*x2) / x1;
        ans = a+b;
        //printf("%lf %lf\n", a, b);
    }

    printf("%.8lf\n", ans);
}