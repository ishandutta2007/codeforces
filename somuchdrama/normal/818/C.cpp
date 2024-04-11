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
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 1e5 + 1;
struct dvn{
    int x1, y1, x2, y2;
} a[MAXN];

int c[MAXN];
int s[MAXN];

int main() {

    int d, n, m;
    cin >> d >> n >> m;
    for (int i = 1; i <= d; ++i) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        if (a[i].x1 > a[i].x2)
            swap(a[i].x1, a[i].x2);
        if (a[i].y1 > a[i].y2)
            swap(a[i].y1, a[i].y2);
    }
    int cl, cr, cu, cd;
    cin >> cl >> cr >> cu >> cd;

    set<int> pot;
    for (int i = 1; i <= d; ++i)
        pot.insert(i);

    {
        memset(c, 0, sizeof c);
        memset(s, 0, sizeof s);
        for (int i = 1; i <= d; ++i) {
            c[a[i].x1]++;
        }
        std::partial_sum(c, c + MAXN, s);
        for (int i = 1; i <= n; ++i)
            dbg(c[i], s[i]);
        for (int i = 1; i <= d; ++i)
            if (s[a[i].x2 - 1] - (a[i].x1 < a[i].x2) != cl)
                pot.erase(i);
    }
    dbg(pot.size());
    {
        memset(c, 0, sizeof c);
        memset(s, 0, sizeof s);
        for (int i = 1; i <= d; ++i) {
            c[a[i].x2]++;
        }
        std::reverse(c, c + MAXN);
        std::partial_sum(c, c + MAXN, s);
        std::reverse(s, s + MAXN);
        for (int i = 1; i <= n; ++i)
            dbg(c[i], s[i]);
        for (int i = 1; i <= d; ++i)
            if (s[a[i].x1 + 1] - (a[i].x1 < a[i].x2) != cr)
                pot.erase(i);
    }
    dbg(pot.size());
    {
        memset(c, 0, sizeof c);
        memset(s, 0, sizeof s);
        for (int i = 1; i <= d; ++i) {
            c[a[i].y1]++;
        }
        std::partial_sum(c, c + MAXN, s);
        for (int i = 1; i <= m; ++i)
            dbg(c[i], s[i]);
        for (int i = 1; i <= d; ++i)
            if (s[a[i].y2 - 1] - (a[i].y1 < a[i].y2) != cu)
                pot.erase(i);
    }
    dbg(pot.size());
    {
        memset(c, 0, sizeof c);
        memset(s, 0, sizeof s);
        for (int i = 1; i <= d; ++i) {
            c[a[i].y2]++;
        }
        std::reverse(c, c + MAXN);
        std::partial_sum(c, c + MAXN, s);
        std::reverse(s, s + MAXN);
        for (int i = 1; i <= m; ++i)
            dbg(c[i], s[i]);
        for (int i = 1; i <= d; ++i)
            if (s[a[i].y1 + 1] - (a[i].y1 < a[i].y2) != cd)
                pot.erase(i);
    }
    dbg(pot.size());

    if (pot.empty()) cout << "-1\n";
    else cout << *pot.begin() << '\n';

    return 0;
}