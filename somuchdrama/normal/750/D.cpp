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

// const int C = 30, D = 8, S = 15;
const int C = 305, D = 8, S = 152;
const int dx[D] = {-1, -1, 0, +1, +1, +1, 0, -1};
const int dy[D] = {0, +1, +1, +1, 0, -1, -1, -1};
bool was[C][C];
bool is[D][C][C];
bool nxt[D][C][C];

int main() {

    int n, len;
    cin >> n;
    is[0][S][S] = 1;
    while (n--) {
        cin >> len;
        for (int d = 0; d < 8; ++d) 
            for (int i = 0; i < C; ++i)
                for (int j = 0; j < C; ++j)
                    if (is[d][i][j]) {
                        for (int s = 1; s <= len; ++s) 
                            was[i + s * dx[d]][j + s * dy[d]] = 1;
                        nxt[(d + 1) % D][i + len * dx[d]][j + len * dy[d]] = nxt[(d - 1 + D) % D][i + len * dx[d]][j + len * dy[d]] = 1;
                    }
        memcpy(is, nxt, D * C * C * sizeof(bool));
        memset(nxt, 0, D * C * C * sizeof(bool));
    }
    int ans = 0;
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < C; ++j)
            ans += was[i][j];
    cout << ans << '\n';

    return 0;
}