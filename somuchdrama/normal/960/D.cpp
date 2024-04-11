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

const int MAXN = 61;
ll shift[MAXN];

int main() {

    int q;
    cin >> q;
    while (q--) {
        ll t, x, k, xl;
        cin >> t >> x;
        for (int l = 0; l < MAXN; ++l)
            if (x >> l & 1)
                xl = l;
        if (t == 1) {
            cin >> k;
            shift[xl] = ((shift[xl] + k + (1LL << xl)) % (1LL << xl) + (1LL << xl)) % (1LL << xl);


        } else if (t == 2) {
            cin >> k;
            for (int l = xl; l < MAXN; ++l) {
                shift[l] = ((shift[l] + k + (1LL << l)) % (1LL << l) + (1LL << l)) % (1LL << l);
                k *= 2;
            }
        } else {
            ll start = 1LL << xl;
            ll pos = start + ((x - start) + shift[xl] + start) % start;

            for (int l = xl; l >= 0; --l) {
                start = 1LL << l;
                ll cur = start + (pos - shift[l] + start) % start;
                cout << cur << ' ';
                pos /= 2;
            }

            cout << '\n';
        }
    }


    return 0;
}