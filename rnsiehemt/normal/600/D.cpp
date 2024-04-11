#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;
typedef long double real;

#define pi 3.141592653589793
#define eps 1e-16

double a, b, c, d, e, f;
real x1, yy1, r1, x2, y2, r2, ans, dist;

int main()
{
    //scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
    //x1 = a; yy1 = b; r1 = c; x2 = d; y2 = e; r2 = f;
    std::cin >> x1 >> yy1 >> r1 >> x2 >> y2 >> r2;
    if (r1 < r2) { std::swap(r1, r2); std::swap(x1, x2); std::swap(yy1, y2); }
    dist = std::sqrt((x1-x2)*(x1-x2) + (yy1-y2)*(yy1-y2));
    if (dist + r2 <= r1 + eps) ans = r2*r2*pi;
    else if (dist >= r1+r2 - eps) ans = 0;
    else {
        real theta = std::acos((dist*dist + r1*r1 - r2*r2) / (2 * dist * r1)) * 2;
        //printf("%Lf %Lf\n", dist, theta);
        ans = theta * r1 * r1 / 2 - std::sin(theta) * r1 * r1 / 2;
        theta = std::acos((dist*dist + r2*r2 - r1*r1) / (2 * dist * r2)) * 2;
        //printf("%Lf %Lf\n", dist, theta);
        real k = theta * r2 * r2 / 2 - std::sin(theta) * r2 * r2 / 2;
        
std::cout.precision(12);
std::cout << std::fixed << ans + k << '\n';
return 0;
    }
    std::cout.precision(12);
    std::cout << std::fixed << ans << '\n';
    //printf("%.12lf\n", double(ans));
}