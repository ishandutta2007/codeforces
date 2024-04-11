#pragma GCC optimize("O3")
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
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 10001;
int cnt[MAXN];
int bits[17000];
vector<int> kal[MAXN];

void prepare(int k) {
    for (int i = 0; i < 17000; ++i)
        bits[i] = __builtin_popcount(i);
    if (!k) {
        for (int i = 0; i < MAXN; ++i)
            kal[i].pb(i);
        return;
    }
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < i; ++j) 
            if (bits[i ^ j] == k) {
                kal[i].pb(j);
                kal[j].pb(i);
            }
    }
}

int main() {
    int n, k, x;
    cin >> n >> k;
    prepare(k);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        for (int j : kal[x])
            ans += cnt[j];
        ++cnt[x];
    }
    cout << ans << '\n';

    return 0;
}