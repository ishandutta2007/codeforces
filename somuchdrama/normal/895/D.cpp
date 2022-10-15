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

const ll MOD = 1'000'000'007;

ll bp(ll a, ll pw) { 
    ll res(1);
    for (; pw; a = (a * a) % MOD, pw /= 2) 
        if (pw & 1) 
            res = (res * a) % MOD;
    return res;
}
ll reverse(ll a) {return bp(a, MOD - 2); }

const int MAXC = 1e6 + 15;

ll fac[MAXC], rfac[MAXC], rev[MAXC];

struct prepare{
    prepare() {
        fac[0] = 1;
        for (int i = 1; i < MAXC; ++i) fac[i] = (fac[i - 1] * i) % MOD;
        rfac[MAXC - 1] = reverse(fac[MAXC - 1]);
        for (int i = MAXC - 2; i >= 0; --i) rfac[i] = (rfac[i + 1] * (i + 1)) % MOD;
        rev[0] = 1;
        for (int i = 1; i < MAXC; ++i) rev[i] = reverse(i);
    }
} prepare;

ll C(ll n, ll k) {
    if (k > n) return 0;
    return (((fac[n] * rfac[k]) % MOD) * rfac[n - k]) % MOD;
}


ll yo(string s, string lim) {
    map<char, int> a;
    for (char c : s)
        ++a[c];
    int n = s.size();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        dbg(i);
        ll as1 = 1;
        ll sz = -1;
        for (auto pp : a) {
            dbg(pp.ff, pp.ss);
            as1 *= rfac[pp.ss];
            as1 %= MOD;
            sz += pp.ss;
        }
        as1 *= fac[sz];
        as1 %= MOD;
        for (auto p : a) {
            if (p.ff < lim[i] && p.ss) {
                dbg(p.ff);
                as1 *= p.ss;
                as1 %= MOD;

                ans += as1;
                ans %= MOD;
                
                as1 *= rev[p.ss];
                as1 %= MOD;
            }
        }
        if (a[lim[i]] == 0)
            break;
        --a[lim[i]];
    }
    return ans;
}

ll s1(string s, string t) {
    ll a1 = yo(s, t);
    t = s;
    ++t.back();
    ll a2 = yo(s, t);
    dbg(a1, a2);
    return (a1 - a2 + MOD) % MOD ;
}

ll s2(string s, string t) {
    string x= s;
    sort(x.begin(), x.end());
    ll ans = 0;
    do { 
        ans += s < x && x < t;
    } while (next_permutation(x.begin(), x.end()));
    return ans;
}

int main() {
    
    string s, t;

    while (0) {
        int n = rand() % 10 + 1;
        s.resize(n, 'a');
        t.resize(n, 'a');
        dbg("TEST");
        for (int i = 0; i < n; ++i)
            if (rand()&1)
                s[i] = 'b';
        for (int i = 0; i < n; ++i)
            if (rand()&1)
                t[i] = 'b';
        if (s > t)
            swap(s, t);
        if (s >= t) continue;
        ll ans1 = s1(s, t), ans2 = s2(s, t);
        if (ans1 != ans2) {
            dbg(n);
            dbg(s);
            dbg(t);
            dbg(ans1, ans2);
            break;
        }
    }
    cin >> s >> t;
    cout << s1(s, t) << '\n';

    return 0;
}