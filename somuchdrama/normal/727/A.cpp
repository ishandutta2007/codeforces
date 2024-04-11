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
    vector<string> _v;\
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
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

set<int> used;
map<int, int> from;
void rec(int b) {
    if (b % 2 == 0)
    {
        int pot = b >> 1;
        if (used.find(pot) == used.end()) {
            used.insert(pot);
            from[pot] = b;
            rec(pot);
        }
    }
    if (b % 10 == 1)
    {
        int pot = b / 10;
        if (used.find(pot) == used.end()) {
            used.insert(pot);
            from[pot] = b;
            rec(pot);
        }        
    }
}

int main() {

    int a, b;
    cin >> a >> b;
    rec(b);
    from[b] = -1;
    if (used.find(a) == used.end())
        cout << "NO\n";
    else {
        cout << "YES\n";
        vector<int> ans;
        int cur = a;
        do {
            ans.pb(cur);
            cur = from[cur];
        } while (cur != -1);
        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}