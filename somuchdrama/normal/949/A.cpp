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

const int MAXN = 2e5 + 1;
vector<int> ans[MAXN];
void no(){
        cout << "-1\n";
        exit(0);}

int main() {
    
    string s;
    cin >> s;
    int n = s.size();
    int a = count(s.begin(), s.end(), '0');
    int b = count(s.begin(), s.end(), '1');
    int z = a - b;
    if (z <= 0) {no();
    }

    set<int> as, bs;

    for (int i = 0; i < z; ++i)
        bs.insert(i);

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' && bs.empty()) no();
        if (s[i] == '1' && as.empty()) no();
        if (s[i] == '0') {
            int p = *(bs.begin());
            bs.erase(p);
            as.insert(p);
            ans[p].pb(i + 1);
        } else {
            int p = *(as.begin());
            as.erase(p);
            bs.insert(p);
            ans[p].pb(i + 1);
        }
    }

    cout << z << '\n';
    for (int i= 0; i < z; ++i) {
        cout << ans[i].size() << ' ';
        for (int j : ans[i])
            cout << j << ' ';
        cout << '\n';
    }
    
    
    return 0;
}