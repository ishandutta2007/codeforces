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

const int MAXN = 2e5 + 25, MAXB = 31;
int a[MAXN];


int leqpow[MAXN];
struct sparse_table_init {
    sparse_table_init() {
        for (int i = 2; i < MAXN; ++i)
            leqpow[i] = leqpow[i / 2] + 1;
    }
} sparse_table_init;

template<typename T>
struct sparse_table_mx {
    vector<vector<T>> sp;
    T get(int l, int r) {
        int k = leqpow[r - l + 1];
        T r1 = sp[k][l], r2 = sp[k][r - (1 << k) + 1];
        return max(r1, r2);
    }
    template<class InputIterator>
    sparse_table_mx(InputIterator begin, InputIterator end, T E = T()) {
        int n = end - begin;
        sp.assign(leqpow[n] + 1, vector<T>(n + n, E));
        copy(begin, end, sp[0].begin());        
        for (int k = 1, pw = 1; pw + pw <= n; ++k, pw *= 2) 
            for (int i = 0; i < n; ++i) 
                sp[k][i] = max(sp[k - 1][i], sp[k - 1][i + pw]);
    }
};

template<typename T>
struct sparse_table_or {
    vector<vector<T>> sp;
    T get(int l, int r) {
        int k = leqpow[r - l + 1];
        T r1 = sp[k][l], r2 = sp[k][r - (1 << k) + 1];
        return r1|r2;
    }
    template<class InputIterator>
    sparse_table_or(InputIterator begin, InputIterator end, T E = T()) {
        int n = end - begin;
        sp.assign(leqpow[n] + 1, vector<T>(n + n, E));
        copy(begin, end, sp[0].begin());        
        for (int k = 1, pw = 1; pw + pw <= n; ++k, pw *= 2) 
            for (int i = 0; i < n; ++i) 
                sp[k][i] = sp[k - 1][i] | sp[k - 1][i + pw];
    }
};

int go[MAXN][MAXB];

int main() {
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = (1 << MAXB -1)- 1;
    for (int j = 0; j < MAXB; ++j)
        go[n + 1][j] = n + 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < MAXB; ++j)
            if (a[i] >> j & 1)
                go[i][j] = i;
            else
                go[i][j] = go[i + 1][j];
    }
    sparse_table_mx<int> mxt(a, a + n + 2);
    sparse_table_or<int> ort(a, a + n + 2);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        set<int> pos;
        for (int j = 0; j < MAXB; ++j) {
            pos.insert(go[i][j]);
            dbg(i, j, go[i][j]);
        }
        pos.insert(n + 1);
        vector<int> yo(pos.begin(), pos.end());
        for (int j = 0; j + 1 < yo.size(); ++j) {
            dbg(j, yo.size());
            int l = yo[j], r = yo[j + 1];
            while (r - l > 1) {
                int m = l + r >> 1;
                // dbg(m);
                if (ort.get(i, m) > mxt.get(i, m))
                    l = m;
                else
                    r = m;
            }
            if (ort.get(i, l) > mxt.get(i, l))
                ans += l - yo[j] + 1;
            dbg(i, yo[j], l);
        }
    }

    cout << ans << '\n';

    return 0;
}