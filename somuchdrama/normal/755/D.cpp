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
const int MAXN = 1e6 + 3;
int n, tree[MAXN];
int get(int i) {
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        res += tree[i];
    return res;
}
void add(int i, int x) {
    for (; i < n; i |= (i + 1))
        tree[i] += x;
}
int get(int l, int r) {
    return get(r) - get(l - 1);
}
int main() {
    int m, k;
    cin >> m >> k;
    if (k + k > m)
        k = m - k;
    n = m + 2;
    ll ans = 1;
    int cur = 1;
    for (int i = 0; i < m; ++i) {
        ++ans;
        int nxt = (cur + k - 1) % m + 1;
        ans += get(cur) + get(nxt);
        cout << ans << ' ';
        if (nxt > cur) {
            add(cur + 1, +1);
            add(nxt, -1);
        } else {
            add(0, +1);
            add(nxt, -1);
            add(cur + 1, +1);
            add(m + 1, -1);
        }
        cur = nxt;
    }


    return 0;
}