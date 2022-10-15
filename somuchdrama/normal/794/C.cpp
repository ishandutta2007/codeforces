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
const int ALP = 26;
int a[ALP], b[ALP];

int main() {

    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), std::greater<char>());
    string ans(s.size(), '?');

    s.resize((s.size() + 1) / 2);
    t.resize(t.size() / 2);
    for (char c : s)
        a[c - 'a']++;
    for (char c : t)
        b[c - 'a']++;

    int n = t.size();

    dbg(s, t, ans);
    int posbeg = 0, posend = ans.size() - 1;

    for (int i = 0; i < n; ++i) {
        {
            char ftmn, ftmx;
            for (int j = ALP - 1; j >= 0; --j)
                if (a[j])
                    ftmn = j + 'a';
            for (int j = ALP - 1; j >= 0; --j)
                if (a[j]) {
                    ftmx = j + 'a';
                    break;
                }
            char sdmn, sdmx;
            for (int j = 0; j < ALP; ++j)
                if (b[j])
                    sdmx = j + 'a';
            for (int j = 0; j < ALP; ++j)
                if (b[j]) {
                    sdmn = j + 'a';
                    break;
                }
            if (ftmn < sdmx) {
                ans[posbeg++] = ftmn;
                --a[ftmn - 'a'];
            } else {
                ans[posend--] = ftmx;
                --a[ftmx - 'a'];
            }
        }
        {
            char ftmn, ftmx;
            for (int j = ALP - 1; j >= 0; --j)
                if (a[j])
                    ftmn = j + 'a';
            for (int j = ALP - 1; j >= 0; --j)
                if (a[j]) {
                    ftmx = j + 'a';
                    break;
                }
            char sdmn, sdmx;
            for (int j = 0; j < ALP; ++j)
                if (b[j])
                    sdmx = j + 'a';
            for (int j = 0; j < ALP; ++j)
                if (b[j]) {
                    sdmn = j + 'a';
                    break;
                }
            if (ftmn < sdmx) {
                ans[posbeg++] = sdmx;
                --b[sdmx - 'a'];
            } else {
                ans[posend--] = sdmn;
                --b[sdmn - 'a'];
            }
        }
    }

    if (ans.size() & 1) {
        for (int i = 0; i < ALP; ++i)
            if (a[i]) {
                ans[posbeg] = 'a' + i;
            }
    }

    cout << ans << '\n';

    return 0;
}