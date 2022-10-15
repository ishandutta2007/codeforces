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
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;


const int MAXN = 55;
char f[MAXN][MAXN];
ll a[MAXN];
ll mb[MAXN];

void no() {
    cout << "No\n";
    exit(0);
}

int main() {

    int n, m;
    cin >> n >> m;
    for (int j = 0; j < MAXN; ++j)
        mb[j] = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> f[i][j];
            if (f[i][j] == '#') {
                a[i] += 1LL << j;
            }
        }
        
        bool b = 1;
        bool c = 1;
        for (int j = 0; j < m; ++j) {
            if (f[i][j] == '#') {
                b &= mb[j] == -1;
                c &= mb[j] == a[i];
            }
        }
        if (c) 
            continue;
        else if (b) {
            for (int j = 0; j < m; ++j) {
                if (f[i][j] == '#') {
                    mb[j] = a[i];
                }
            }
        } else {
            no();
        }
    }

    cout << "Yes\n";


    return 0;
}