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
const int MAXN = 1e5 + 15, MAXF = 1e4 + 20;
struct fenwick {
    int n = 0;
    vector<int> tree;
    fenwick() {}
    fenwick(int _n) {
        tree.assign(n = _n, 0);
    }
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
};

vector<pii> byf[MAXF];
vector<pii> pot[MAXF];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x, r, f;
        cin >> x >> r >> f;
        byf[f].pb(x, x + r);
        for (int j = max(f - k, 0); j <= min(MAXF, f + k); ++j)
            pot[j].pb(x - r, x);
    }

    ll ans = 0;
    for (int i = 0; i < MAXF; ++i) {
        if (byf[i].empty()) 
            continue;

        sort(byf[i].begin(), byf[i].end());
        sort(pot[i].begin(), pot[i].end());
        
        vector<int> alc;
        
        for (pii p : byf[i]) {
            alc.pb(p.ff); 
            alc.pb(p.ss);
        }
        
        for (pii p : pot[i]) {
            alc.pb(p.ff);
            alc.pb(p.ss);
        }

        sort(alc.begin(), alc.end());
        alc.resize(unique(alc.begin(), alc.end()) - alc.begin());

        std::unordered_map<int, int> crd;
        for (uint yo = 0; yo < alc.size(); ++yo) 
            crd[alc[yo]] = yo;

        fenwick fwt(alc.size());
        int sz = pot[i].size();
        int ptr = 0;
        for (pii p : byf[i]) {
            while (ptr < sz && pot[i][ptr].ff <= p.ff) {
                fwt.add(crd[pot[i][ptr].ss], 1);
                ptr++;
            }
            ans += fwt.get(crd[p.ff], crd[p.ss]);
        }
    }

    ans -= n;

    cout << ans << '\n';

    return 0;
}