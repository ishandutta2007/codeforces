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

typedef tree<pair<long long, int>, null_type, less<pair<long long, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template<int MOD>
struct ModInt {
    long long v;
    ModInt(long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt& operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt& operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt& operator *= (const ModInt &other) {v = v * other.v % MOD; return *this;}
    ModInt& operator /= (const ModInt &other) {return *this *= inverse(other);}
    bool operator == (const ModInt &other) const {return v == other.v;}
    bool operator != (const ModInt &other) const {return v != other.v;}
    friend ModInt operator + (ModInt a, const ModInt &b) {return a += b;}
    friend ModInt operator - (ModInt a, const ModInt &b) {return a -= b;}
    friend ModInt operator * (ModInt a, const ModInt &b) {return a *= b;}
    friend ModInt operator / (ModInt a, const ModInt &b) {return a /= b;}
    friend ModInt operator - (const ModInt &a) {return 0 - a;}
    friend ModInt power(ModInt a, long long b) {ModInt ret(1); while (b > 0) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
    friend ModInt inverse(ModInt a) {return power(a, MOD - 2);}
    friend istream& operator >> (istream &is, ModInt &m) {is >> m.v; m.v = (-MOD < m.v && m.v < MOD) ? m.v : m.v % MOD; if (m.v < 0) m.v += MOD; return is;}
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
typedef ModInt<998244353> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        vector<long long> pref(n), prefParity(n);
        for (int i=0; i<n; i++) {
            pref[i] = a[i] + (i > 0 ? pref[i-1] : 0);
            prefParity[i] = a[i] + (i >= 2 ? prefParity[i-2] : 0);
        }

        auto query = [&] (int l, int r) -> long long {
            if (l > r) return 0;
            return pref[r] - (l > 0 ? pref[l-1] : 0);
        };

        auto queryParity = [&] (int l, int r) -> long long {
            if (l > r) return 0;
            return prefParity[r] - (l - (l % 2 == r % 2) > 0 ? prefParity[l - (l % 2 == r % 2) - 1] : 0);
        };

        M ret = 0;

        // PPP...PPP CCC...CCC
        for (int i=0; i<n; i++)
            if (pref[i] > query(i + 1, n - 1))
                ret += 1;

        // P CCC...CCC PCPCPC...PC PPP...PPP C
        for (int st=0; st<2; st++)
            for (int nd=0; nd<2; nd++) {
                vector<ordered_set> ost(2);
                for (int i=st; i<n-nd; i++)
                    ost[i % 2].insert({(nd > 0 ? a[n-1] : 0) + query(st, i) + queryParity(i + 2, n - nd - 1 - (i % 2 == (n - nd) % 2)) - queryParity(i + 1, n - nd - 1 - (i % 2 != (n - nd) % 2)), i});
                vector<long long> delta(2);
                for (int j=n-nd-1; j>=st; j--) {
                    ost[j % 2].erase({(nd > 0 ? a[n-1] : 0) + query(st, j) + queryParity(j + 2, n - nd - 1 - (j % 2 == (n - nd) % 2)) - queryParity(j + 1, n - nd - 1 - (j % 2 != (n - nd) % 2)), j});
                    delta[j % 2] -= a[j];
                    delta[(j % 2) ^ 1] += a[j];
                    ret += ost[(j % 2) ^ 1].order_of_key({(st > 0 ? a[0] : 0) + query(j, n - nd - 1) - delta[(j % 2) ^ 1], -1});
                }
            }
        cout << ret << "\n";
    }

    return 0;
}