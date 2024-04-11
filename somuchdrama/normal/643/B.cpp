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



int main() {

    int n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    if (k <= n) {
        cout << "-1\n";
        return 0;
    }
    if (n == 4) {
        cout << "-1\n";
        return 0;
    }

    vector<char> used(n + 1, false);
    used[0] = used[a] = used[b] = used[c] = used[d] = true;
    vector<int> way;
    for (int i = 1; i <= n; ++i) {
        if (!used[i])
            way.pb(i);
    }

    cout << a << ' ' << c << ' ';
    for (int i : way)
        cout << i << ' ';
    cout << d << ' ' <<  b << '\n';
    cout << c << ' ' << a << ' ';
    for (int i : way)
        cout << i << ' ';
    cout << b << ' '  << d << '\n';


    return 0;
}