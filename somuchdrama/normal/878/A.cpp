// 
//     
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

const int B = 10;
int go[B][2];

int main() {

int n;
    cin >> n;
    for (int i = 0; i < B; ++i) {
        go[i][0] = 0;
        go[i][1] = 1;
    }

    while (n--) {
        int x ;
        char c;
        cin >> c >> x;
        for (int i = 0; i < B; ++i) {
            int bit = x >> i;
            for (int j = 0; j < 2; ++j) {
                if (c == '|') {
                    go[i][j] |= bit & 1;
                } else if (c == '^') {
                    go[i][j] ^= bit & 1;
                } else {
                    go[i][j] &= bit & 1;
                }
            }
        }
    }

    cout << "3\n";
    {
        int num = 0;
        for (int i = 0; i < B; ++i) {
            if (go[i][0] == 1 && go[i][1] == 0) {
                num += 1 << i;
            }
        }
        cout << "^ " << num << '\n';
    }
    {
        int num = 0;
        for (int i = 0; i < B; ++i) {
            if (go[i][0] == 1 && go[i][1] == 1) {
                num += 1 << i;
            }
        }
        cout << "| " << num << '\n';
    }
    {
        int num = 1023;
        for (int i = 0; i < B; ++i) {
            if (go[i][0] == 0 && go[i][1] == 0) {
                num -= 1 << i;
            }
        }
        cout << "& " << num << '\n';
    }


    return 0;
}