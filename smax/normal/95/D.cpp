#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int MAXN = 1005;

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
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
typedef ModInt<1000000007> M;

int t, k;
M dp[MAXN][MAXN][2], pref[MAXN][MAXN], lucky[MAXN];

M solve(const string &s, int i = 0, int last = -1) {
    if (i == (int) s.size())
        return 0;
    int numLucky = ('4' < s[i]) + ('7' < s[i]), cnt = (int) (s[i] - '0') - numLucky, len = (int) s.size() - i - 1;
    M ret = 0;
    // choose lucky digit
    if (last != -1 && i - last <= k)
        ret += numLucky * power(M(10), len);
    else
        ret += numLucky * (lucky[len] + pref[len][min(len, k)]);
    // choose unlucky digit
    ret += cnt * (lucky[len] + (last == -1 ? 0 : pref[len][min(len, max(last + k - i, 0))]));
    // choose equal digit
    if ((s[i] == '4' || s[i] == '7') && last != -1 && i - last <= k) {
        M cur = 0;
        for (int j=i+1; j<(int)s.size(); j++)
            cur = 10 * cur + (s[j] - '0');
        return ret + cur + 1;
    }
    return ret + solve(s, i + 1, s[i] == '4' || s[i] == '7' ? i : last);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> k;

    // length, position of last lucky digit, is it nearly lucky?
    // position value of 0 signifies no lucky digit yet
    dp[0][0][0] = 1;
    for (int i=0; i<=1000; i++) {
        for (int j=0; j<=i; j++)
            for (int b=0; b<2; b++) {
                // choose lucky digit
                dp[i+1][i+1][b|(j!=0 && i+1-j<=k)] += 2 * dp[i][j][b];
                // choose unlucky digit
                dp[i+1][j][b] += 8 * dp[i][j][b];
                if (b)
                    lucky[i] += dp[i][j][b];
            }
        for (int j=1; j<=i; j++)
            pref[i][j] = dp[i][i-j+1][0] + pref[i][j-1];
    }

    while (t--) {
        string l, r;
        cin >> l >> r;
        int last = -1;
        bool ok = false;
        for (int i=0; i<(int)l.size(); i++)
            if (l[i] == '4' || l[i] == '7') {
                if (last != -1 && i - last <= k) {
                    ok = true;
                    break;
                }
                last = i;
            }
        cout << solve(r) - solve(l) + ok << "\n";
    }

    return 0;
}