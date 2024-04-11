// vk.com/godsngods --   ,   ,     

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

const int MAXN = 3017;
int dp[MAXN];
int from[MAXN];
bool gl[256];

int main() {

    string s;
    cin >> s;
    int n = s.size();
    s = "#" + s;
    
    gl['a'] = gl['e'] = gl['i'] = gl['o'] = gl['u'] = 1;

    for (int i = 0; i <= n; ++i)
        dp[i] = MAXN;
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        string go = "";
        for (int j = i + 1; j <= n; ++j) {
            go += s[j];
            int sz = go.size();
            if (sz >= 3 && !gl[go[sz - 3]] && !gl[go[sz - 2]] && !gl[s[j]] && (s[j] != go[sz - 2] || go[sz - 3] != go[sz - 2]))
                break;
            if (dp[j] > dp[i] + 1) {
                dp[j] = dp[i] + 1;
                from[j] = i;
            }
        }
    }

    vector<int> ps;
    int pos = n;
    while (pos) {
        ps.pb(pos);
        pos = from[pos];
    }
    ps.pb(0);

    reverse(ps.begin(), ps.end());
    for (int i = 1; i < ps.size(); ++i) {
        for (int j = ps[i - 1] + 1; j <= ps[i]; ++j)
            cout << s[j];
        cout << ' ';
    }
    cout << '\n';

    return 0;
}