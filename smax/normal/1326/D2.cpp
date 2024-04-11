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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

typedef unsigned long long ull;

struct PolyHash {
    static const ull MOD = (1ULL << 61) - 1;
    static int BASE;

    static inline ull add(ull a, ull b) {
        a += b;
        if (a >= MOD)
            a -= MOD;
        return a;
    }

    static inline ull sub(ull a, ull b) {
        a -= b;
        if (a >= MOD)
            a += MOD;
        return a;
    }

    static inline ull mul(ull a, ull b) {
        ull l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
        ull l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        ull ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & MOD) + (ret >> 61);
        ret = (ret & MOD) + (ret >> 61);
        return ret - 1;
    }

    vector<ull> power, pref;

    PolyHash(const string &s) : pref(s.length() + 1) {
        while (power.size() <= s.length())
            power.push_back(power.empty() ? 1 : mul(power.back(), BASE));

        for (int i=0; i<(int)s.length(); i++)
            pref[i+1] = add(mul(pref[i], BASE), s[i]);
    }

    ull operator () (int pos, int len) const {
        return sub(pref[pos + len], mul(pref[pos], power[len]));
    }
};

int gen() {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed ^ ull(new ull));
    uniform_int_distribution<int> dist(258, 2e9 - 1);
    int base = dist(gen);
    return base % 2 == 0 ? base - 1 : base;
}

int PolyHash::BASE = gen();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();

        int k = 0;
        while (k < n - k - 1 && s[k] == s[n-k-1])
            k++;
        if (k >= n - k - 1) {
            cout << s << "\n";
            continue;
        }

        string sub = s.substr(k, n - 2 * k);
        PolyHash hs(sub), hr(string(sub.rbegin(), sub.rend()));
        int m = (int) sub.size(), pref = 0, suff = 0;
        for (int i=1; i<=m; i++) {
            if (hs(0, i) == hr(m - i, i))
                pref = i;
            if (hs(m - i, i) == hr(0, i))
                suff = i;
        }

        if (pref > suff)
            cout << s.substr(0, k) << sub.substr(0, pref) << s.substr(n - k) << "\n";
        else
            cout << s.substr(0, k) << sub.substr(m - suff) << s.substr(n - k) << "\n";
    }

    return 0;
}