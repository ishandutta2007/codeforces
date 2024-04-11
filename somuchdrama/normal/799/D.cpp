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

const int MAXN = 1e5, KAL = 34, IT = 5e5;
ll ks[MAXN];
int nums[KAL];
bool used[KAL];

int main() {

    ll a, b, h, w; int n;
    cin >> a >> b >> h >> w >> n;
    for (int i = 0; i < n; ++i)
        cin >> ks[i];
    std::sort(ks, ks + n, std::greater<ll>());

    n = min(n, KAL);
    int ans = 300;
    std::iota(nums, nums + n, 0);
    for (int it = 0; it < IT; ++it) {
        std::random_shuffle(nums, nums + n);
        {
            memset(used, 0, sizeof used);
            ll ca = h;
            int i = 0, c = 0;
            for (; ca < a && i < n; ++i) {
                ca *= ks[nums[i]];
                used[nums[i]] = 1;
            }
            ll cb = w;
            for (int j = 0; cb < b && j < n; ++j) 
                if (!used[j])
                    cb *= ks[j], ++c;
            if (ca >= a && cb >= b)
                ans = min(ans, i + c);
        }
        swap(h, w);
        {
            memset(used, 0, sizeof used);
            ll ca = h;
            int i = 0, c = 0;
            for (; ca < a && i < n; ++i) {
                ca *= ks[nums[i]];
                used[nums[i]] = 1;
            }
            ll cb = w;
            for (int j = 0; cb < b && j < n; ++j) 
                if (!used[j])
                    cb *= ks[j], ++c;
            if (ca >= a && cb >= b)
                ans = min(ans, i + c);
        }
        swap(h, w);
    }
    if (ans == 300)
        ans /= -300;
    cout << ans << '\n';

    return 0;
}