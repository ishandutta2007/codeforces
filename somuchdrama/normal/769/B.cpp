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

const int MAXN = 101;
int a[MAXN];
int q[MAXN];
int u[MAXN];

int main() {

    int n, l = 0, r = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    q[r++] = u[1] = 1;
    vector<pii> ans;
    while (l < r) {
        vector<int> cand;
        for (int i = 1; i <= n; ++i)
            if (!u[i])
                cand.pb(i);
        sort(cand.begin(), cand.end(), [&](const int & p1, const int & p2) {
            return a[p1] > a[p2];
        });
        int v = q[l++];
        for (int i = 0; i < min((int)cand.size(), a[v]); ++i) {
            ans.pb(v, cand[i]);
            u[q[r++] = cand[i]] = 1;
        }
    }

    if (r < n) 
        cout << "-1\n";
    else {
        cout << ans.size() << '\n';
        for (pii p : ans)
            cout << p.ff << ' ' << p.ss << '\n';
    }

    return 0;
}