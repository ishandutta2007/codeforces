//   

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
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 1000, S = 5;
struct pt{
    int a[S];
} pts[MAXN];
struct vc{
    int a[S];
    vc(){}
    vc(pt x, pt y) {
        for (int i = 0; i < S; ++i)
            a[i] = y.a[i] - x.a[i];
    }
} vcs[MAXN][MAXN];
bool operator *(vc a, vc b) {
    int res = 0;
    for (int i = 0; i < S; ++i)
        res += a.a[i] * b.a[i];
    return res > 0;
}


int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < S; ++j)
            cin >> pts[i].a[j];
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            vcs[i][j] = vc(pts[i], pts[j]);

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        bool ok = 1;
        for (int j = 0; j < n && ok; ++j) {
            if (i == j) continue;
            for (int k = 0; k < j && ok; ++k) {
                if (i == k) continue;
                if (vcs[i][j] * vcs[i][k]) ok = 0;
            }
        }
        if (ok) ans.pb(i+1);
    }

    cout << ans.size() << '\n';
    for (int i : ans) cout << i << '\n';


    return 0;
}