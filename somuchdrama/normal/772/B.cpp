#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        #ifdef LOCAL
        srand(300); 
        #else
        srand(time(0));
        #endif
    }
    ~init() {
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;
#define double long double
struct point
{
double x, y;
point(double a, double b) : x(a), y(b) {}
point() {}
};
std::istream & operator >>(std::istream & is, point & p) {
    return is >> p.x >> p.y;
}

struct vect
{
double x, y;
vect(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
double length() { return hypot(x, y); }
};
struct line
{
double a, b, c;
line(point x, point y)
{
a = y.y - x.y;
b = x.x - y.x;
c = -(a * x.x + b * x.y);
}
};
double dot_product(vect first, vect second)
{
return first.x * second.x + first.y * second.y;
}
int sign(double a)
{
if (a < 0)
return -1;
else
return 1;
}
double dist_to_line(point p, line l)
{
return abs(l.a * p.x + l.b * p.y + l.c) / hypot(l.a, l.b);
}
double dist_to_ray(point p, point a, point b)
{
if (sign(dot_product(vect(a, b), vect(a, p))) > 0)
return dist_to_line(p, line(a, b));
else
return vect(p, a).length();
}
double dist_to_segment(point p, point a, point b)
{
return max(dist_to_ray(p, a, b), dist_to_ray(p, b, a));
}
const int MAXN = 1111;
point a[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    a[n] = a[0];
    a[n + 1] = a[1];

    double ans = 1e10;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dist_to_segment(a[i], a[i - 1], a[i + 1]));
    }

    cout << ans / 2.0 << '\n';


    return 0;
}