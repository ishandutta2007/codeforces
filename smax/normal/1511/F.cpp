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
using M = ModInt<998244353>;

template<typename T>
vector<T> berlekampMassey(const vector<T> &s) {
    vector<T> c;    // the linear recurrence sequence we are building
    vector<T> oldC; // the best previous version of c to use (the one with the rightmost left endpoint)
    int f = -1;     // the index at which the best previous version of c failed on
    for (int i=0; i<(int)s.size(); i++) {
        // evaluate c(i)
        // delta = s_i - \sum_{j=1}^n c_j s_{i-j}
        // if delta == 0, c(i) is correct
        T delta = s[i];
        for (int j=1; j<=(int)c.size(); j++)
            delta -= c[j-1] * s[i-j];   // c_j is one-indexed, so we actually need index j - 1 in the code
        if (delta == 0)
            continue;   // c(i) is correct, keep going
        // now at this point, delta != 0, so we need to adjust it
        if (f == -1) {
            // this is the first time we're updating c
            // s_i was the first non-zero element we encountered
            // we make c of length i + 1 so that s_i is part of the base case
            c.resize(i + 1);
            mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
            for (T &x : c)
                x = rng();  // just to prove that the initial values don't matter in the first step, I will set to random values
            f = i;
        } else {
            // we need to use a previous version of c to improve on this one
            // apply the 5 steps to build d
            // 1. set d equal to our chosen sequence
            vector<T> d = oldC;
            // 2. multiply the sequence by -1
            for (T &x : d)
                x = -x;
            // 3. insert a 1 at the front
            d.insert(d.begin(), 1);
            // 4. multiply the sequence by delta / d(f + 1)
            T df1 = 0;  // d(f + 1)
            for (int j=1; j<=(int)d.size(); j++)
                df1 += d[j-1] * s[f+1-j];
            assert(df1 != 0);
            T coef = delta / df1;   // storing this in outer variable so it's O(n^2) instead of O(n^2 log MOD)
            for (T &x : d)
                x *= coef;
            // 5. insert i - f - 1 zeros in front
            vector<T> zeros(i - f - 1);
            zeros.insert(zeros.end(), d.begin(), d.end());
            d = zeros;
            // now we have our new recurrence: c + d
            vector<T> temp = c; // save the last version of c because it might have a better left endpoint
            c.resize(max(c.size(), d.size()));
            for (int j=0; j<(int)d.size(); j++)
                c[j] += d[j];
            // finally, let's consider updating oldC
            if (i - (int) temp.size() > f - (int) oldC.size()) {
                // better left endpoint, let's update!
                oldC = temp;
                f = i;
            }
        }
    }
    return c;
}

template<typename T>
T solve(const vector<T> &c, const vector<T> &s, long long k) {
    int n = (int) c.size();
    assert(c.size() <= s.size());

    auto mul = [&] (const vector<T> &a, const vector<T> &b) -> vector<T> {
        vector<T> ret(a.size() + b.size() - 1);
        for (int i=0; i<(int)a.size(); i++)
            for (int j=0; j<(int)b.size(); j++)
                ret[i+j] += a[i] * b[j];
        for (int i=(int)ret.size()-1; i>=n; i--)
            for (int j=n-1; j>=0; j--)
                ret[i-j-1] += ret[i] * c[j];
        ret.resize(min((int) ret.size(), n));
        return ret;
    };

    vector<T> a = n == 1 ? vector<T>{c[0]} : vector<T>{0, 1}, x{1};
    for (; k>0; k/=2) {
        if (k % 2)
            x = mul(x, a);
        a = mul(a, a);
    }
    x.resize(n);

    T ret = 0;
    for (int i=0; i<n; i++)
        ret += x[i] * s[i];
    return ret;
}

M dp[8][5][8][5], ndp[8][5][8][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> nxt(26);
    for (int i=0; i<n; i++) {
        cin >> s[i];
        nxt[s[i][0]-'a'].push_back(i);
    }

    dp[0][0][0][0] = 1;
    vector<M> seq{1};
    for (int i=0; i<min(m, 2000); i++) {
        for (int a=0; a<n; a++)
            for (int la=0; la<(int)s[a].size(); la++)
                for (int b=0; b<n; b++)
                    for (int lb=0; lb<(int)s[b].size(); lb++)
                        ndp[a][la][b][lb] = 0;
        for (int a=0; a<n; a++)
            for (int la=0; la<(int)s[a].size(); la++)
                for (int b=0; b<n; b++)
                    for (int lb=0; lb<(int)s[b].size(); lb++)
                        for (char c='a'; c<='z'; c++) {
                            if ((la != 0 && s[a][la] != c) || (lb != 0 && s[b][lb] != c))
                                continue;
                            if (la == 0) {
                                if (lb == 0) {
                                    for (int j : nxt[c-'a'])
                                        for (int k : nxt[c-'a'])
                                            ndp[j][s[j].size() > 1][k][s[k].size() > 1] += dp[a][la][b][lb];
                                } else {
                                    for (int j : nxt[c-'a'])
                                        ndp[j][s[j].size() > 1][b][lb + 1 == (int) s[b].size() ? 0 : lb + 1] += dp[a][la][b][lb];
                                }
                            } else if (lb == 0) {
                                for (int k : nxt[c-'a'])
                                    ndp[a][la + 1 == (int) s[a].size() ? 0 : la + 1][k][s[k].size() > 1] += dp[a][la][b][lb];
                            } else {
                                ndp[a][la + 1 == (int) s[a].size() ? 0 : la + 1][b][lb + 1 == (int) s[b].size() ? 0 : lb + 1] += dp[a][la][b][lb];
                            }
                        }
        memcpy(dp, ndp, sizeof(ndp));
        M cur = 0;
        for (int a=0; a<n; a++)
            for (int b=0; b<n; b++)
                cur += dp[a][0][b][0];
        seq.push_back(cur);
    }

    if (m < (int) seq.size())
        cout << seq[m] << "\n";
    else
        cout << solve(berlekampMassey(seq), seq, m) << "\n";

    return 0;
}