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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

const int MOD = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int dp[3005][3005];
bool uniq[3005][3005], ok[5];
gp_hash_table<ull, null_type> ban;
gp_hash_table<ull, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (const string &s : {"1100", "1010", "0111", "1111"}) {
        ull cur = 0;
        for (char c : s)
            cur = PolyHash::add(PolyHash::mul(cur, PolyHash::BASE), c);
        ban.insert(cur);
    }

    int m;
    cin >> m;
    string s(m, '0');
    for (int i=m-1; i>=0; i--)
        cin >> s[i];

    for (int len=1; len<=m; len++) {
        mp.clear();
        ull pw = 1;
        for (int i=0; i<len; i++)
            pw = PolyHash::mul(pw, PolyHash::BASE);
        ull cur = 0;
        for (int i=0; i<len; i++)
            cur = PolyHash::add(PolyHash::mul(cur, PolyHash::BASE), s[i]);
        mp[cur] = 0;
        for (int i=len; i<m; i++) {
            cur = PolyHash::add(PolyHash::sub(PolyHash::mul(cur, PolyHash::BASE), PolyHash::mul(pw, s[i-len])), s[i]);
            mp[cur] = i - len + 1;
        }
        for (auto &p : mp)
            uniq[p.second][p.second + len - 1] = true;
    }

    int ret = 0;
    for (int i=m-1; i>=0; i--) {
        ull cur = 0;
        memset(ok, false, sizeof(ok));
        for (int len=1; len<=min(m-i, 4); len++) {
            cur = PolyHash::add(PolyHash::mul(cur, PolyHash::BASE), s[i+len-1]);
            ok[len] = ban.find(cur) == ban.end();
        }
        for (int j=i; j<m; j++) {
            for (int len=1; len<=min(j-i+1, 4); len++)
                if (ok[len])
                    add(dp[i][j], i + len <= j ? dp[i+len][j] : 1);
            if (uniq[i][j])
                add(ret, dp[i][j]);
        }
        cout << ret << "\n";
    }

    return 0;
}