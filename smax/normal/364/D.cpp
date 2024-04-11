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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto start = clock();

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
    long long ret = 0;
    while (clock() - start < 3.5 * CLOCKS_PER_SEC) {
        long long cand = a[uniform_int_distribution<int>(0, n - 1)(rng)];
        vector<long long> d;
        for (long long i=1; i*i<=cand; i++)
            if (cand % i == 0) {
                d.push_back(i);
                if (cand / i != i) d.push_back(cand / i);
            }
        unordered_map<long long, int> mp;
        for (int i=0; i<n; i++)
            mp[__gcd(cand, a[i])]++;
        for (long long x : d) {
            int cur = 0;
            for (auto [y, cnt] : mp)
                if (y % x == 0)
                    cur += cnt;
            if (cur * 2 >= n)
                ret = max(ret, x);
        }
    }
    cout << ret << "\n";

    return 0;
}