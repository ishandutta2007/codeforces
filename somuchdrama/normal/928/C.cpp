//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
template<typename T> 
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h <<"\n"; 
}
template<typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
    int _b = 0;
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++; 
    cerr << " = " << _h << ","; 
    _dbg(_s+1, _t...);
}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
        srand(300); 
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 2018; 
map<pair<string, int>, vector<pair<string, int>>> dep; 
map<string, int> t, love, kal; 
int main() {

    int n; 
    cin >> n; 
    string poly;
    for (int i = 0; i < n; ++i) {
        string name; 
        int v, k; 
        cin >> name >> v >> k; 
        if (!i) t[name] = love[poly = name] = v; 
        for (int j = 0; j < k; ++j) {
            string boom; 
            int meow; 
            cin >> boom >> meow; 
            dep[{name, v}].pb(boom, meow); 
        }
    }
    while (!love.empty()) {
        for (auto p : love)
            for (auto w : dep[p])
                if (t.find(w.ff) == t.end() && (kal.find(w.ff) == kal.end() || kal[w.ff] < w.ss)) 
                    kal[w.ff] = w.ss;
        love = kal;
        for (auto p : kal)
            t.insert(p);
        kal.clear();
    }
    cout << t.size() - 1 << '\n'; 
    for (auto p : t)
        if (p.ff != poly)
            cout << p.ff << ' ' << p.ss << '\n'; 

    return 0; 
}