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
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

struct figure {
    char c;
    int val;
    figure() {}
    figure(char _c, int _val) : c(_c) , val(_val) {}
};

map<int, vector<figure>> rows, cols, d1, d2;

void add(char c, int x, int y) {
    rows[x].pb(c, y);
    cols[y].pb(c, x);
    d1[x - y].pb(c, x + y);
    d2[x + y].pb(c, x - y);
}

void yes() {
    cout << "YES\n";
    exit(0);
}

int main() {
    int n;
    cin >> n;

    int kx, ky;
    cin >> kx >> ky;
    add('K', kx, ky);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c >> kx >> ky;
        add(c, kx, ky);
    }

    for (auto & p : rows) {
        sort(p.ss.begin(), p.ss.end(), [](const figure & a, const figure & b){
            return a.val < b.val;
        });
        for (int i = 0; i < p.ss.size(); ++i) {
            if (p.ss[i].c == 'K') {
                if (i > 0 && (p.ss[i - 1].c == 'R' || p.ss[i - 1].c == 'Q')) 
                    yes();
                if (i + 1 < p.ss.size() && (p.ss[i + 1].c == 'R' || p.ss[i + 1].c == 'Q')) 
                    yes();
            }
        }
    }
    for (auto & p : cols) {
        sort(p.ss.begin(), p.ss.end(), [](const figure & a, const figure & b){
            return a.val < b.val;
        });

        for (int i = 0; i < p.ss.size(); ++i) {
            if (p.ss[i].c == 'K') {
                if (i > 0 && (p.ss[i - 1].c == 'R' || p.ss[i - 1].c == 'Q')) 
                    yes();
                if (i + 1 < p.ss.size() && (p.ss[i + 1].c == 'R' || p.ss[i + 1].c == 'Q')) 
                    yes();
            }
        }
    }
    for (auto & p : d1) {
        sort(p.ss.begin(), p.ss.end(), [](const figure & a, const figure & b){
            return a.val < b.val;
        });

        for (int i = 0; i < p.ss.size(); ++i) {
            if (p.ss[i].c == 'K') {
                if (i > 0 && (p.ss[i - 1].c == 'B' || p.ss[i - 1].c == 'Q')) 
                    yes();
                if (i + 1 < p.ss.size() && (p.ss[i + 1].c == 'B' || p.ss[i + 1].c == 'Q')) 
                    yes();
            }
        }
    }
    for (auto & p : d2) {
        sort(p.ss.begin(), p.ss.end(), [](const figure & a, const figure & b){
            return a.val < b.val;
        });

        for (int i = 0; i < p.ss.size(); ++i) {
            if (p.ss[i].c == 'K') {
                if (i > 0 && (p.ss[i - 1].c == 'B' || p.ss[i - 1].c == 'Q')) 
                    yes();
                if (i + 1 < p.ss.size() && (p.ss[i + 1].c == 'B' || p.ss[i + 1].c == 'Q')) 
                    yes();
            }
        }
    }

    cout << "NO\n";
    return 0;


    return 0;
}