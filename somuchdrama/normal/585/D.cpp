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
//  //
//  //
//  //
//  //
//  //

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;
template<typename T>
void cmx(T & x, T y) {if (x < y) x = y;}
const int MAXN = 25, INF = 1e9;
int ya[MAXN], yb[MAXN], yc[MAXN];
map<pii, pii> yo;
int n;
ll pw = 1;
void g1(int c = 0, int ca = 0, int cb = 0, int cc = 0, int code = 0) {
    if (c == n/2) {
        if (yo.find({ca - cb, cb - cc}) == yo.end())
            yo[{ca - cb, cb - cc}] = {-INF, 0};
        cmx(yo[{ca - cb, cb - cc}], {ca, code});
    } else {
        g1(c + 1, ca + ya[c], cb + yb[c], cc, code * 3 + 0);
        g1(c + 1, ca + ya[c], cb, cc + yc[c], code * 3 + 1);
        g1(c + 1, ca, cb + yb[c], cc + yc[c], code * 3 + 2);
    }
}

pll ans = {-INF, 0};
void g2(int c = n / 2, int ca = 0, int cb = 0, int cc = 0, int code = 0) {
    if (c == n) {
        auto it = yo.find({cb - ca, cc - cb});
        if (it != yo.end())
            cmx(ans, {ca + it->ss.ff, it->ss.ss * pw + code});
    } else {
        g2(c + 1, ca + ya[c], cb + yb[c], cc, code * 3 + 0);
        g2(c + 1, ca + ya[c], cb, cc + yc[c], code * 3 + 1);
        g2(c + 1, ca, cb + yb[c], cc + yc[c], code * 3 + 2);
    }
}

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ya[i] >> yb[i] >> yc[i];

    for (int i = 0; i < n-n/2; ++i)
        pw *= 3;

    g1();
    g2();

    if (ans.ff == -INF)
        cout << "Impossible\n";
    else {
        vector<string> ws;
        for (int i = 0; i < n; ++i) {
            if (ans.ss % 3 == 0) ws.pb("LM");
            else if (ans.ss % 3 == 1) ws.pb("LW");
            else ws.pb("MW");
            ans.ss /= 3;
        }
        reverse(ws.begin(), ws.end());
        for (auto i : ws)
            cout << i << '\n';
    }

    return 0;
}