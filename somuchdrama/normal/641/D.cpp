//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //

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
template<typename T> 
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h <<"\n"; 
}
template<typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
    int _b = 0;
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++; 
    cerr << " = " << _h << ","; 
    _dbg(_s+1, _t...);
}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(6);
        cerr << std::fixed << std::setprecision(5);
        srand(300); 
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 1e5 + 17;
const double EPS = 1e-10;
double mx[MAXN], mn[MAXN], a[MAXN], b[MAXN];

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> mx[i];
    for (int i = 1; i <= n; ++i)
        cin >> mn[i];

    double smx = 0, smn = 1;
    for (int i = 1; i <= n; ++i) {
        smx += mx[i];
        smn -= mn[i];
        double A = 1, B = smn - smx - 1, C = smx;
        double D = sqrt(max(0., B * B - 4 * A * C));
        a[i] = (-B - D) / (A + A);
        b[i] = (-B + D) / (A + A);
    }

    for (int i = 1; i <= n; ++i)
        cout << max(0., a[i] - a[i - 1]) << ' ';
    cout << '\n';
    for (int i = 1; i <= n; ++i)
        cout << max(0., b[i] - b[i - 1]) << ' ';
    cout << '\n';

    return 0;
}