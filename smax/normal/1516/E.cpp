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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto chooseBig = [] (int n, int k) -> M {
        M ret = 1;
        for (int i=0; i<k; i++) {
            ret *= n - i;
            ret /= i + 1;
        }
        return ret;
    };

    int n, k;
    cin >> n >> k;

    vector<vector<M>> dp(2 * k + 1, vector<M>(k + 1));
    dp[0][0] = 1;
    for (int i=1; i<=2*k; i++)
        for (int j=0; j<=k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j > 0) dp[i][j] += (i - 1) * dp[i-1][j-1];
        }

    vector<vector<M>> chooseSmall(2 * k + 1, vector<M>(2 * k + 1));
    for (int i=0; i<=2*k; i++)
        chooseSmall[i][0] = 1;
    for (int i=1; i<=2*k; i++)
        for (int j=1; j<=2*k; j++)
            chooseSmall[i][j] = chooseSmall[i-1][j] + chooseSmall[i-1][j-1];

    vector<M> ret(k + 1);
    ret[0] = 1;
    for (int j=1; j<=k; j++) {
        for (int i=1; i<=min(n, 2*j); i++) {
            M ways = 0;
            for (int l=0; l<=i; l++)
                ways += (l % 2 ? -1 : 1) * chooseSmall[i][l] * dp[i-l][j];
            ret[j] += ways * chooseBig(n, i);
        }
        if (j >= 2)
            ret[j] += ret[j-2];
        cout << ret[j] << " ";
    }
    cout << "\n";

    return 0;
}