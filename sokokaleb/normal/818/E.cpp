#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
    cin.tie(0);

#ifdef __WIN32__
    char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using pdd = pair<double,double>;
using vpdd = vector<pdd>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using umultiset = unordered_multiset<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using umultimap = unordered_multimap<K, V>;

const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <typename T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <typename T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T>
inline bool inRange(const T& z, const T& a, const T& b){return a <= z && z <= b;}

void OPEN(const string& in = "input.txt", const string& out = "output.txt")
{
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
    return ;
}

//using sokokaleb's template v4.0

#define N 100005
#define PRIME_LIM 31700
int n, k;
int arr[N];
vi factorized[N], fct;

vi primes;
bitset<PRIME_LIM + 1> isp;

int cnt_pow[PRIME_LIM + 1];
map<int, int> cnt_pow_large;

void factorize(const int& x, vi& res) {
    res.clear();
    int xx = x;
    for (const auto& p : primes) {
        if (1LL * p * p > xx) {
            break ;
        }
        while (xx % p == 0) {
            res.pb(p);
            xx /= p;
        }
    }
    if (xx != 1) {
        res.pb(xx);
    }
    return ;
}

int cnt_minus = 0;

void remove(int x) {
    if (x <= PRIME_LIM) {
        if (cnt_pow[x] == 0) {
            ++cnt_minus;
        }
        --cnt_pow[x];
        // cerr << x << " = " << cnt_pow[x] << endl;
    } else {
        if (cnt_pow_large.find(x) == cnt_pow_large.end()) {
            cnt_pow_large[x] = 0;
        }
        int& val = cnt_pow_large[x];
        if (val == 0) {
            ++cnt_minus;
        }
        --val;
        // cerr << x << " = " << val << endl;
    }
    return ;
}

void add(int x) {
    if (x <= PRIME_LIM) {
        if (cnt_pow[x] == -1) {
            --cnt_minus;
        }
        ++cnt_pow[x];
    } else {
        if (cnt_pow_large.find(x) == cnt_pow_large.end()) {
            cnt_pow_large[x] = 0;
        }
        int& val = cnt_pow_large[x];
        if (val == -1) {
            --cnt_minus;
        }
        ++val;
    }
    return ;
}

void batch_add(const vi& vc) {
    for (const auto& p : vc) {
        add(p);
    }
}

void batch_remove(const vi& vc) {
    for (const auto& p : vc) {
        remove(p);
    }
}

int main(int argc, char** argv) {
    __INIT_CC__

    isp.set();
    FORN (i, 2, PRIME_LIM) {
        if (isp.test(i)) {
            primes.pb(i);
            for (ll c = 1LL * i * i; c <= PRIME_LIM; c += i) {
                isp.set(c, 0);
            }
        }
    }

    cin >> n >> k;
    FOR (i, 0, n) {
        cin >> arr[i];
        factorize(arr[i], factorized[i]);
    }
    factorize(k, fct);
    batch_remove(fct);
    // cerr << "OK" << endl;

    int r = 0;
    batch_add(factorized[r]);
    ++r;
    ll ans = 0LL;
    FOR (l, 0, n) {
        while (r < n && cnt_minus > 0) {
            batch_add(factorized[r]);
            ++r;
        }
        // cerr << cnt_minus << ": " << l << " " << r << endl;
        if (cnt_minus <= 0) {
            ans += n - r + 1;
        }
        batch_remove(factorized[l]);
        while (r <= l + 1) {
            batch_add(factorized[r]);
            ++r;
        }
    }

    cout << ans << "\n";
}