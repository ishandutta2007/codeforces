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

const int MAXN = 1e5 + 1, KAL = 333;
int t[MAXN], p[MAXN], x[MAXN];
int a[KAL][KAL];
int bal[KAL], mx[KAL];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> p[i];
        if (p[i]) cin >> x[i];
        else x[i] = -1;
        --t[i];
        int bl = t[i] / KAL;
        a[bl][t[i] % KAL] = x[i];
        int cur = 0, start = 0;
        mx[bl] = 0;
        for (int j = KAL - 1; j >= 0; --j) {
            if (a[bl][j] > 0) ++cur;
            else if (a[bl][j] < 0) --cur;
            dbg(j, cur, mx[bl]);
            if (cur > mx[bl]) mx[bl] = cur;
        }
        bal[bl] = cur;
        cur = 0;
        int ans = -1;
        for (int j = KAL - 1; j >= 0; --j) {
            int cmx = cur + mx[j];
            dbg(j, cmx, cur, bal[j], mx[j]);;
            if (cmx > 0) {
                for (int pos = KAL - 1; pos >= 0; --pos) {
                    if (a[j][pos] > 0) ++cur;
                    else if (a[j][pos] < 0) --cur;
                    if (cur == 1) {
                        ans = a[j][pos];
                        break;
                    }
                }
                break;
            }
            cur += bal[j];
        }
        cout << ans << '\n';
    }   



    return 0;
}