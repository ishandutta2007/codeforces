#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const uint64_t MOD = (1ULL << 61) - 1;
const int BASE = [] () {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed ^ uint64_t(new uint64_t));
    uniform_int_distribution<int> dist(3e5 + 2, 2e9 - 1);
    int base = dist(gen);
    return base % 2 == 0 ? base - 1 : base;
} ();

uint64_t add(uint64_t a, uint64_t b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

uint64_t sub(uint64_t a, uint64_t b) {
    a -= b;
    if (a >= MOD)
        a += MOD;
    return a;
}

uint64_t mul(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & MOD) + (ret >> 61);
    ret = (ret & MOD) + (ret >> 61);
    return ret - 1;
}

uint64_t getHash(const string &s) {
    uint64_t ret = 0;
    for (char c : s)
        ret = add(mul(ret, BASE), c);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t a = BASE, denom = 1;
    for (uint64_t b=MOD-2; b>0; b/=2) {
        if (b % 2) denom = mul(denom, a);
        a = mul(a, a);
    }

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        long long ret = 0;

        auto solve = [&] (auto &self, int l, int r) -> void {
            if (l == r)
                return;
            int m = (l + r) / 2;
            self(self, l, m);
            self(self, m + 1, r);
            unordered_map<uint64_t, int> mp;
            uint64_t hsh = 0;
            vector<int> stk;
            for (int i=m; i>=l; i--) {
                if (!stk.empty() && stk.back() == a[i]) {
                    hsh = mul(sub(hsh, a[i]), denom);
                    stk.pop_back();
                } else {
                    hsh = add(mul(hsh, BASE), a[i]);
                    stk.push_back(a[i]);
                }
                mp[hsh]++;
            }
            hsh = 0;
            stk.clear();
            for (int i=m+1; i<=r; i++) {
                if (!stk.empty() && stk.back() == a[i]) {
                    hsh = mul(sub(hsh, a[i]), denom);
                    stk.pop_back();
                } else {
                    hsh = add(mul(hsh, BASE), a[i]);
                    stk.push_back(a[i]);
                }
                ret += mp.count(hsh) ? mp[hsh] : 0;
            }
        };

        solve(solve, 0, n - 1);
        cout << ret << "\n";
    }

    return 0;
}