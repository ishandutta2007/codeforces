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

    mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

    int n, m, p;
    cin >> n >> m >> p;
    vector<long long> a(n);
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++)
            if (s[j] == '1')
                a[i] |= 1LL << j;
    }

    shuffle(a.begin(), a.end(), rng);
    long long ret = 0;
    for (int z=0; z<min(n, 50); z++) {
        vector<int> bits;
        for (int i=0; i<m; i++)
            if (a[z] & (1LL << i))
                bits.push_back(i);
        int k = (int) bits.size();
        assert(k <= p);

        vector<int> dp(1 << k);
        for (long long x : a) {
            int mask = 0;
            for (int i=0; i<k; i++)
                if (x & (1LL << bits[i]))
                    mask |= 1 << i;
            dp[mask]++;
        }

        for (int i=0; i<k; i++)
            for (int mask=0; mask<1<<k; mask++)
                if (mask & (1 << i))
                    dp[mask ^ (1 << i)] += dp[mask];

        for (int mask=0; mask<1<<k; mask++)
            if (dp[mask] >= (n + 1) / 2 && __builtin_popcount(mask) > __builtin_popcountll(ret)) {
                ret = 0;
                for (int i=0; i<k; i++)
                    if (mask & (1 << i))
                        ret |= 1LL << bits[i];
            }
    }

    for (int i=0; i<m; i++)
        cout << ((ret >> i) & 1);
    cout << "\n";

    return 0;
}