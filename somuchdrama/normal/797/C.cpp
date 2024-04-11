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

const int MAXN = 1e5 + 1;
int a[MAXN];
int wmn[MAXN];

int main() {

    string s;
    cin >> s;
    int n = s.size();
    string t;
    string u;

    s += 'z' + 1;
    wmn[n] = n;
    for (int i = n - 1; i >= 0; --i) 
        wmn[i] = s[i] <= s[wmn[i + 1]] ? i : wmn[i + 1];

    for (int i = 0, pos = 0; i < n; ++i) {
        if (i < wmn[pos])
            t += s[i];
        else if (i == wmn[pos]) {
            u += s[i];
            pos = i + 1;
            while (!t.empty() && t.back() <= s[wmn[pos]]) {
                u += t.back();
                t.pop_back();
            }
        } else assert(false);
    }

    cout << u << '\n';

    return 0;
}