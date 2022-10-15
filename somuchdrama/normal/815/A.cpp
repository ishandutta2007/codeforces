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


const int MAXN = 111;

int a[MAXN][MAXN];

int dh[MAXN], dv[MAXN];

void no() {
    cout << "-1\n";
    exit(0);
}

int ph[MAXN], pv[MAXN];

int f[MAXN][MAXN];

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];


    for (int i = 1; i < n; ++i) 
        dv[i] = a[i][1] - a[i + 1][1];

    for (int j = 1; j < m; ++j)
        dh[j] = a[1][j] - a[1][j + 1];


    for (int i = 2; i <= n; ++i) 
        for (int j = 1; j < m; ++j)
            if (a[i][j] - a[i][j + 1] != dh[j])
                no();

    for (int j = 2; j <= m; ++j)
        for (int i = 1; i < n; ++i)
            if (a[i][j] - a[i + 1][j] != dv[i])
                no();
    ph[1] = 0;
    int mnh = 0;
    for (int i = 2; i <= m; ++i) {
        ph[i] = ph[i - 1] - dh[i - 1];
        mnh = min(mnh, ph[i]);
    }

    pv[1] = 0;
    int mnv = 0;
    for (int i = 2; i <= n; ++i) {
        pv[i] = pv[i - 1] - dv[i - 1];
        mnv = min(mnv, pv[i]);
    }

    for (int i = 1; i <= m; ++i) {
        ph[i] -= mnh;
        dbg(ph[i]);
    }

    for (int i = 1; i <= n; ++i) {
        pv[i] -= mnv;
        dbg(pv[i]);
    }

    int all = a[1][1] - (pv[1] + ph[1]);

    if (n < m)
        for (int i = 1; i <= n; ++i)
            pv[i] += all;
    else
        for (int i = 1; i <= m; ++i)
            ph[i] += all;

    vector<int> ansh, ansv;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < pv[i]; ++j)
            ansv.pb(i);

    for (int j = 1; j <= m; ++j)
        for (int i = 0; i < ph[j]; ++i)
            ansh.pb(j);

    cout << ansv.size() + ansh.size() << '\n';

    for (int i : ansv)
        cout << "row " << i << '\n';

    for (int i : ansh)
        cout << "col " << i << '\n';

    return 0;
}