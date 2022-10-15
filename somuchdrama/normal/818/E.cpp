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

const int MAXN = 1e5 + 1, MAXD = 33;
int a[MAXN];
int c[MAXD][MAXN];
int s[MAXD][MAXN];

inline int get(int l, int r, int d) {
    return s[d][r] - s[d][l - 1];
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<pii> dvs;
    int e = k;
    for (int i = 2; i * i <= k; ++i) {
        if (e % i == 0) {
            dvs.pb(i, 0);
            while (e % i == 0) {
                e /= i;
                dvs.back().ss++;
            }
        }
    }
    if (e > 1)
        dvs.pb(e, 1);

    int d = dvs.size();

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j < d; ++j) {
            while (a[i] % dvs[j].ff == 0) {
                a[i] /= dvs[j].ff;
                c[j][i]++;
            }
        }
    }

    for (int j = 0; j < d; ++j) 
        for (int i = 1; i <= n; ++i)
            s[j][i] = s[j][i - 1] + c[j][i];

    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        bool gok = 1;
        for (int j = 0; j < d; ++j)
            if (get(i, n, j) < dvs[j].ss)
                gok = 0;
        if (!gok) break;
        int l = i - 1, r = n;
        while (r - l > 1) {
            int m = l + r >> 1;
            bool ok = 1;
            for (int j = 0; ok && j < d; ++j)
                if (get(i, m, j) < dvs[j].ss) 
                    ok = 0;
            if (ok) r = m;
            else l = m;
        }
        ans += n - r + 1;
    }

    cout << ans << '\n';

    return 0;
}