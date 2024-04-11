// vk.com/godsngods --   ,   ,     

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

std::unordered_map<string, int> cnt;
const int MAXN = 70000, S = 9;
string a[MAXN];
int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        set<string> s;
        for (int j = 0; j < S; ++j) {
            string kal = "";
            for (int k = j; k < S; ++k) {
                kal += a[i][k];
                s.insert(kal);
            }
        }
        for (auto & z : s)
            ++cnt[z];
    }

    for (int i = 0; i < n; ++i) {
        int ans = S;
        string wans = a[i];
        for (int j = 0; j < S; ++j) {
            string kal = "";
            for (int k = j; k < S; ++k) {
                kal += a[i][k];
                if (cnt[kal] == 1 && k - j + 1 < ans) {
                    ans = k - j + 1;
                    wans = kal;
                }
            }
        }
        cout << wans << '\n';
    }


    return 0;
}