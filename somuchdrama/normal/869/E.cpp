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

const int MAXN = 2502;
int tree[MAXN][MAXN];
int val[MAXN][MAXN];
void plu(int x, int y, int yo) {
    for (int i = x; i < MAXN; i += i &-i)
        for (int j = y; j < MAXN; j += j &-j)
            tree[i][j] += yo;
}
void add(int x1, int y1, int x2, int y2) {
    val[x1][y1] = (rand() + 1) * (rand() + 1);
    plu(x1 - 1, y1 - 1, +val[x1][y1]);
    plu(x1 - 1, y2,     -val[x1][y1]);
    plu(x2,     y1 - 1, -val[x1][y1]);
    plu(x2,     y2,     +val[x1][y1]);
}
void del(int x1, int y1, int x2, int y2) {
    plu(x1 - 1, y1 - 1, -val[x1][y1]);
    plu(x1 - 1, y2,     +val[x1][y1]);
    plu(x2,     y1 - 1, +val[x1][y1]);
    plu(x2,     y2,     -val[x1][y1]);
}
int get(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i &-i)
        for (int j = y; j; j -= j &-j)
            res += tree[i][j];
    return res;
}
const string answer[] = {"No\n", "Yes\n"};
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        if (t == 1) 
            add(x1, y1, x2, y2);
        else if (t == 2)
            del(x1, y1, x2, y2);
        else
            cout << answer[get(x1 - 1, y1 - 1) == get(x2 - 1, y2 - 1)];
    }
    
    return 0;
}