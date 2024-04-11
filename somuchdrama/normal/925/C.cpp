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
/////////////////////// 1 -> 1LL
const int MAXN = 1e5 + 15, B = 60;
ll b[MAXN];
ll r[MAXN];

void no() {
    cout << "No\n";
    exit(0);
}

vector<ll> ans[B + 1];
// vector<int> g[MAXN];
bool used[MAXN];

int main() {
    // while (1) {


    int n = rand() % 4 + 1;
    cin >> n;
    // dbg(n);
    // set<int> rs;
    // while (rs.size() < n){
    //     rs.insert(rand() % 10 + 1);
    // }
    // for (int i = 0; i <= B; ++i)
    //     ans[i].clear();

    // for (int i = 1; i <= n; ++i) {
    //     used[i] = 0;
    //     r[i] = *(rs.begin());
    //     rs.erase(rs.begin());
    //     dbg(r[i]);
    // }

    for (int i = 1; i <= n; ++i) {
        b[i] = r[i-1] ^ r[i];
        dbg(b[i]);
        cin >> b[i];
    }

    // std::random_shuffle(b + 1, b + n + 1);

    // int x = 0;
    for (int bit = B - 1; bit >= 0; --bit) {
        // int c = 0;
        vector<ll> xex;
        for (int i = 1; i <= n; ++i)
            if (b[i] >> bit & 1LL) {
                if (!used[i]) {
                    used[i] = 1;
                    xex.pb(b[i]);
                }
                // c++;
            }
        // if (c > x + x + 1) no();
        // x = c;
        uint t = 0;
        if (xex.size())
            ans[bit].pb(xex[t++]);
        for (ll i : ans[bit + 1]) {
            // cerr << i << ' ';
            ans[bit].pb(i);
            if ((i >> bit & 1LL) && t < xex.size())
                ans[bit].pb(xex[t++]);
        }
        // cerr << '\n';
    }
    ll w = 0;
    ll a = 0;
    if (ans[0].size() != n) 
        no();
    for (ll i : ans[0]) {
        a ^= i;
        if (a <= w) {
            no();
        }
        w = a;
    }

    cout << "Yes\n";
    for (ll i : ans[0]) {
        cout << i << ' ';
    }
    cout << '\n';

    // }

    return 0;
}