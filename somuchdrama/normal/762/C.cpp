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

const int MAXN = 1e5 + 2, A = 26;
int next[MAXN][A];
int prev[MAXN][A];

int pref[MAXN], suf[MAXN];

int main() {

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = "#" + s + "#";

    for (int i = 1; i <= n + 1; ++i)  {
        for (int j = 0; j < A; ++j) 
            prev[i][j] = prev[i - 1][j];
        if (i <= n)
            prev[i][s[i] - 'a'] = i;
    }

    for (int i = n; i >= 0; --i) {
        for (int j = 0; j < A; ++j)
            next[i][j] = next[i + 1][j];
        if (i)
            next[i][s[i] - 'a'] = i;
    }


    for (int j = 0; j < m; ++j) pref[j] = -1;
    for (int j = 0; j < n + 2; ++j) suf[j] = -1;
    int pos = 0;
    for (int j = 0; j < m; ++j) {
        if (next[pos + 1][t[j] - 'a'] == 0)
            break;
        pos = next[pos + 1][t[j] - 'a'];
        pref[j] = pos;
    }

    pos = n + 1;
    for (int j = m - 1; j >= 0; --j) {
        if (prev[pos - 1][t[j] - 'a'] == 0)
            break;
        pos = prev[pos - 1][t[j] - 'a'];
        dbg(pos);
        suf[pos] = j;
    }
    suf[n + 1] = m;
    for (int i = n; i >= 1; --i) {
        if (suf[i] == -1)
            suf[i] = suf[i + 1];
        dbg(i, suf[i]);
    }

    int ans = MAXN, l, r;
    for (int j = 0; j < m; ++j) {
        if (pref[j] != -1) {
            dbg(j, pref[j], suf[pref[j] + 1]);
            int curl = j, curr = max(suf[pref[j] + 1], j + 1);
            int cur = curr - curl - 1;
            dbg(ans, cur);
            if (ans > cur) {
                ans = cur;
                l = curl;
                r = curr;
            }
        } 
    }   

    {
        int curl = -1, curr = suf[1];
        if (curr != m) {
            int cur = curr - curl - 1;
            dbg(ans, cur);
            if (ans > cur) {
                ans = cur;
                l = curl;
                r = curr;
            }
        }
    }

    dbg(ans, l, r);

    if (ans > m) cout << "-\n";
    else {
        for (int j = 0; j <= l; ++j)
            cout << t[j];
        for (int j = r; j < m; ++j)
            cout << t[j];
        cout << '\n';
    }


    return 0;
}