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
        srand(time(0));
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

struct segment_tree {
    int n, sh;
    vector<int> tree;
    segment_tree() {}
    segment_tree(const vector<int> & a) {
        n = a.size();
        sh = 1;
        while (sh < n)
            sh *= 2;
        tree.resize(sh * 2, 0);
        for (int i = 0; i < n; ++i) 
            tree[sh + i] = a[i];
        for (int i = sh - 1; i > 0; --i) 
            tree[i] = tree[i + i] + tree[i + i + 1];
    }
    void update(int i, int val) { 
        for (tree[i += sh] = val; i /= 2; ) 
            tree[i] = tree[i + i] + tree[i + i + 1];
    }
    int get(int l, int r) { // [l..r)
        int res = 0;
        for (l += sh, r += sh; l < r; l /= 2, r /= 2) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

const int MAXN = 1e5 + 1;
int a[MAXN];
vector<int> w[MAXN];
int n;

ll solve1() {
    for (int i = 0; i < MAXN; ++i)
        w[i].clear();
    for (int i = 0; i < n; ++i) {
        w[a[i]].pb(i);
    }
    segment_tree st(vector<int>(n, 0));
    int pos = 0;
    ll ans = 0;
    for (int i = 1; i < MAXN; ++i) {
        vector<int> nw;
        for (int cur : w[i]) 
            if (cur >= pos) 
                nw.pb(cur);
        for (int cur : w[i]) 
            if (cur < pos) 
                nw.pb(cur);
        for (int cur : nw) {
            dbg(pos, cur);
            dbg(ans);
            if (pos <= cur) ans += cur - pos - st.get(pos, cur);
            else ans += n - pos - st.get(pos, n) + cur - st.get(0, cur);
            ++ans;
            dbg(ans);
            pos = cur;
            st.update(pos, 1);
        }
    }
    return ans;
}
bool used[MAXN];
ll solve2() {
    ll ans = 0;
    std::multiset<int> s;
    for (int i = 0; i < n; ++i)
        s.insert(a[i]);
    while (!s.empty()) {
        dbg(*s.begin(), ans);
        for (int i = 0; i < n && !s.empty(); ++i) {
            if (a[i] != -1)
                ++ans;
            if (*s.begin() == a[i]) {
                s.erase(s.begin());
                a[i] = -1;
            }
        }
    }
    return ans;
}

int main() {
    // while (1) {
        n = rand() % 7 + 1;
        cin >> n;
        dbg(n);
        for (int i = 0; i < n; ++i) {
            a[i] = rand() % 5 + 1;
            cin >> a[i];
            dbg(a[i]);
        }
        ll xx = solve1();
        cout << xx << '\n';
        // ll yy = solve2();
        // dbg(xx, yy);
        // if (xx != yy) break;
    // }

    return 0;
}