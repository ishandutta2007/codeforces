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

vector<int> zfunc(const string & s) {
    int n = s.length();
    vector<int> z(n, 0);
    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) {
        if (i < right)
            z[i] = min(z[i - left], right - i);
        while ((s[z[i]] == s[i + z[i]]) && (i + z[i] < n))
            ++z[i];
        if (i + z[i] > right) {
            left = i;
            right = i + z[i];
        }
    }
    return z;
}

bool con(string s, string t) {
    // string nw = s + "#" + t;
    // auto z = zfunc(nw);
    auto n = s.size(), m = t.size();
    // for (auto i = n; i < nw.size(); ++i)
    //     if (z[i] == n)
    //         return 1;
    for (int i = 0; i + m <= n; ++i) {
        bool ok = 1;
        for (int j = 0; j < m && ok; ++j)
            ok &= s[i + j] == t[j];
        if (ok) return 1;
    }
    return 0;
}

string tos(int n, int x) {
    string res;
    for (int i = 0; i < n; ++i) {
        if (x >> i & 1)
            res += '1';
        else
            res += '0';
    }
    return res;
}

const int MAXN = 201;
// #ifdef LOCAL
// const int MAXA = 4;
// #else
const int MAXA = 14;
// #endif
std::bitset<1 << MAXA> used[MAXN][MAXA];
string s[MAXN];
string begin[MAXN];
string end[MAXN];


int main() {

    int n = 100;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        // s[i] = string(100, '1');
        cin >> s[i];
        for (int j = 0; j < MAXA; ++j) {
            for (int mask = 0; mask < (1 << j); ++mask) {
                // dbg(s[i], mask, tos(j, mask), con(s[i], tos(j, mask)));
                used[i][j][mask] = con(s[i], tos(j, mask));
            }
            // dbg(j, used[i][j]);
        }
        for (int j = 0; j < min(MAXA, (int)s[i].size()); ++j)
            begin[i] += s[i][j];
        for (int j = max(0, (int)s[i].size() - MAXA); j < s[i].size(); ++j)
            end[i] += s[i][j];
    }

    int q = 100;
    cin >> q;
    for (int i = n + 1; i <= n + q; ++i) {
        int a, b;
        a = i - 1, b = i - 1;
        cin >> a >> b;
        begin[i] = begin[a];
        end[i] = end[b];
        if (end[i].size() < MAXA) {
            end[i] = end[a] + end[b];
            reverse(end[i].begin(), end[i].end());
            while (end[i].size() > MAXA)
                end[i].pop_back();
            reverse(end[i].begin(), end[i].end());
        }
        if (begin[i].size() < MAXA) {
            begin[i] = begin[a] + begin[b];
            while (begin[i].size() > MAXA)
                begin[i].pop_back();
        }
        for (int j = 0; j < MAXA; ++j) {
            used[i][j] = used[a][j] | used[b][j];
            // dbg(i, j, used[i][j]);
        }
        string op = end[a] + begin[b];
        // dbg(op);
        for (int j = 0; j < MAXA; ++j) {
            for (int mask = 0; mask < (1 << j); ++mask)
                if (!used[i][j][mask])
                    used[i][j][mask] = con(op, tos(j, mask));
        }
        for (int ans = 1; ans < MAXA; ++ans) {
            if (used[i][ans].count() != (1 << ans)) {
                cout << ans-1 << '\n';
                break;
            }
        }
    }


    return 0;
}