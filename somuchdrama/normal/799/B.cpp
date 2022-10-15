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
const int MAXN = 2e5;
int a[MAXN], b[MAXN], p[MAXN];

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    set<pii> s[3];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        s[a[i]].insert({p[i], i});
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        s[b[i]].insert({p[i], i});
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        --x;
        if (s[x].empty()) {
            cout << "-1 ";
        } else {
            pii pp = *s[x].begin();
            cout << pp.ff << ' ';
            int num = pp.ss;
            s[a[num]].erase(pp);
            s[b[num]].erase(pp);
        }
    }
    cout << '\n';
    return 0;
}