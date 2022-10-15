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
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif
#define int ll

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
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

const int MAXN = 5e6;
#ifdef LOCAL
const int MAXA = 228;
#else
const int MAXA = 2e6 + 1;
#endif
int a[MAXN], c[MAXA];
int pref[MAXN];
int sum[MAXN];
int sumpref[MAXN];

int get(int l, int r) {
    return pref[r] - pref[l - 1];
}

int getsum(int l, int r) {
    return sumpref[r] - sumpref[l - 1];
}

int32_t main() {

    int n, x, y;
    cin >> n >> x >> y;
    int k = x / y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        ++c[a[i]];
        sum[a[i]] += a[i];
    }

    std::partial_sum(c, c + MAXA, pref);
    std::partial_sum(sum, sum + MAXA, sumpref);

    int ans = n * x;

    for (int i = 2; i < MAXA; ++i) {
        dbg(i);
        int pot = 0;
        for (int j = i; j < MAXA; j += i) {
            dbg(j);
            int r = j - min(i, k + 1);
            dbg(r);
            dbg(get(j - i + 1, r));
            dbg(get(r + 1, j));
            dbg(get(r + 1, j) * j);
            dbg(getsum(r, j));
            pot += x * get(j - i + 1, r) + y * (j * get(r + 1, j) - getsum(r + 1, j));
            dbg(pot);
        }
        if (ans > pot)
            ans = pot;
        dbg("===");
    }

    cout << ans << '\n';

    return 0;
}