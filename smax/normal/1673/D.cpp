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
using M = ModInt<1000000007>;

#define int long long

map<int, int> factor(int x) {
    map<int, int> mp;
    for (int p=2; p*p<=x; p++)
        if (x % p == 0) {
            int &cnt = mp[p];
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
        }
    if (x > 1)
        mp[x]++;
    return mp;
}

int power(int a, int b) {
    int ret = 1;
    for (; b>0; b/=2) {
        if (b % 2) ret *= a;
        a *= a;
    }
    return ret;
}

int floorDiv(int a, int b) {
    return a >= 0 ? a / b : (a - b + 1) / b;
}

int countRangeCong(int a, int b, int x, int p) {
    return floorDiv(b - x, p) - floorDiv(a - 1 - x, p);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int b, q, y, c, r, z;
        cin >> b >> q >> y >> c >> r >> z;

        int bp = b + (y - 1) * q, cp = c + (z - 1) * r;
        if (b > c || bp < cp || (b % q + q) % q != (c % q + q) % q) {
            cout << "0\n";
            continue;
        }

        map<int, int> factQ = factor(q), factR = factor(r);
        vector<pair<int, int>> optional;
        int need = 1;
        M ret = 0;
        bool infinity = false;

        auto dfs = [&] (auto &self, int i, int p) -> void {
            if (i == (int) optional.size()) {
                int targ = (c % p + p) % p;
                int lcnt = countRangeCong(c - r + 1, c, targ, p), rcnt = countRangeCong(cp, cp + r - 1, targ, p);
                if ((b > c - r && rcnt > 0) || (bp < cp + r && lcnt > 0))
                    infinity = true;
                else
                    ret += M(lcnt) * rcnt;
                return;
            }
            self(self, i + 1, p);
            for (int j=0; j<optional[i].second; j++) {
                p *= optional[i].first;
                self(self, i + 1, p);
            }
        };

        for (const auto &p : factQ) {
            if (!factR.contains(p.first) || p.second > factR[p.first]) {
                cout << "0\n";
                goto done;
            }
            if (p.second == factR[p.first])
                optional.push_back(p);
            else
                need *= power(p.first, factR[p.first]);
        }
        for (const auto &p : factR)
            if (!factQ.contains(p.first))
                need *= power(p.first, p.second);

        // a <= b and ap >= bp
        if (b > c - r && bp < cp + r) {
            cout << "-1\n";
            continue;
        }

        dfs(dfs, 0, need);
        if (infinity) cout << "-1\n";
        else cout << ret << "\n";
        done:;
    }

    return 0;
}