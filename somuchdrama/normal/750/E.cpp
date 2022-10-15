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

const int C = 5, INF = 1e9;
const string twok17 = "2017";
struct matrix{
    int dp[C][C];
    matrix() {
        for (int i = 0; i < C; ++i) 
            for (int j = 0; j < C; ++j)
                dp[i][j] = INF;
    }
    void set(char x) {
        for (int i = 0; i < C; ++i) dp[i][i] = 0;
        int i = find(twok17.begin(), twok17.end(), x) - twok17.begin();
        if (x == '6') {
            dp[3][3] = 1;
            dp[4][4] = 1;
        } else if (i != C - 1) {
            dp[i][i] = 1;
            dp[i][i + 1] = 0;
        } 
    }
};

matrix operator +(const matrix & l, const matrix & r) {
    matrix result;
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < C; ++j)
            for (int k = i; k <= j; ++k)
                if (result.dp[i][j] > l.dp[i][k] + r.dp[k][j])
                    result.dp[i][j] = l.dp[i][k] + r.dp[k][j];
    return result;
}

struct segment_tree {
    int n, sh;
    vector<matrix> tree;
    segment_tree() {}
    segment_tree(const string & s) {
        tree.resize(2 * (sh = 1 << 32 - __builtin_clz((n = s.size()) - 1)), matrix());
        for (int i = 0; i < n; ++i) 
            tree[sh + i].set(s[i]);
        for (int i = n; i < sh; ++i)
            tree[sh + i].set('@');
        for (int i = sh - 1; i > 0; --i) 
            tree[i] = tree[i + i] + tree[i + i + 1];
    }
    void get(int v, int tl, int tr, int l, int r, matrix & result) {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r) {
            result = result + tree[v];
            return;
        }
        int tm = tl + tr >> 1;
        get(v + v, tl, tm, l, r, result);
        get(v + v + 1, tm + 1, tr, l, r, result);
    }
    matrix get(int l, int r) {
        matrix result;
        result.set('$');
        get(1, 0, sh - 1, l, r, result);
        return result;
    }
};

int main() {

    int n, q;
    string s;
    cin >> n >> q >> s;
    segment_tree st(s);
    while (q--) {
        int a, b;
        cin >> a >> b;
        int ans = st.get(a - 1, b - 1).dp[0][4];
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}