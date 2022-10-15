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
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 1e6 + 1, KAL = 100;
int p[MAXN];
bool used[MAXN];

int main() {

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    vector<int> cps;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            cps.pb(0);
            int cur = i;
            do {
                used[cur] = true;
                cur = p[cur];
                ++cps.back();
            } while (cur != i);
        }
    }

    map<int, int> cnt;
    for (int i : cps)
        ++cnt[i];

    vector<int> nel;
    for (pii pp : cnt) {
        for (int i = 0; (1 << i) <= pp.ss; ++i) {
            nel.pb((1 << i) * pp.ff);
            pp.ss -= 1 << i;
        }
        if (pp.ss)
            nel.pb(pp.ss * pp.ff);
    }

    std::bitset<MAXN> knap;
    knap[0] = 1;
    for (int i : nel)
        knap |= knap << i;

    int mn = knap[k] ? k : k + 1;

    sort(cps.begin(), cps.end(), std::greater<int>());

    int mx = 0, left = k;
    for (int & i : cps) {
        if (!left) break;
        int kal = min(i / 2, left);
        i &= 1;
        mx += kal * 2;
        left -= kal;
    }

    for (int i : cps) {
        if (!left) break;
        mx += i;
        left -= i;
    }

    cout << mn << ' ' << mx << '\n';

    return 0;
}