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

using myf = long double;
#define double long double
const int MAXN = 1e5, INF = 1e9;
const double EPS = 0;
inline bool less(myf a, myf b) {return a + EPS < b;}
inline bool greater(myf a, myf b) {return a > b + EPS;}
inline bool equal(myf a, myf b) {return abs(a - b) / max(myf(1), abs(a)) <= EPS;}
inline bool leq(myf a, myf b) {return less(a, b) || equal(a, b);}
inline bool geq(myf a, myf b) {return greater(a, b) || equal(a, b);}
void no() {
    cout << "-1\n";
    exit( 0 );
}

bool btw(double a, double o, double b) {
    return less(a, o) && less(o, b);
}

pair<double, double> solve(double x1, double x2, double r, double v) {
    if (equal(v, 0)) {
        if (btw(x1, r, x2)) return {0, INF};
        else no();
    } else {
        if (less(r, x1) && greater(v, 0)) return {(x1 - r) / v, (x2 - r) / v};
        if (less(r, x1) && less(v, 0)) no();
        if (greater(r, x2) && less(v, 0)) return {(x2 - r) / v, (x1 - r) / v};
        if (greater(r, x2) && greater(v, 0)) no();
        if (greater(v, 0)) return {0, (x2 - r) / v};
        return {0, (x1 - r) / v};
    }
}

int main() {
    int n;
    cin >> n;
    int x1,y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double l = 0, r = INF;
    for (int i = 0; i < n; ++i) {
        int rx, ry, vx, vy;
        double txl, txr, tyl, tyr;
        cin >> rx >> ry >> vx >> vy;
        auto tx = solve(x1, x2, rx, vx);
        auto ty = solve(y1, y2, ry, vy);
        txl = tx.ff;
        txr = tx.ss;
        tyl = ty.ff;
        tyr = ty.ss;
        l = max(l, txl);
        l = max(l, tyl);
        r = min(r, txr);
        r = min(r, tyr);
    }

    if (geq(l, r)) no();

    cout << l << '\n';


    return 0;
}