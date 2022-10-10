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

const int MAX = 1e5 + 5;

M fact[MAX], inv[MAX];

M choose(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fact[n] * inv[k] * inv[n-k];
}

void preprocess() {
    fact[0] = 1;
    for (int i=1; i<MAX; i++)
        fact[i] = fact[i-1] * i;
    inv[MAX-1] = inverse(fact[MAX-1]);
    for (int i=MAX-2; i>=0; i--)
        inv[i] = inv[i+1] * (i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preprocess();

    int n;
    cin >> n;
    long long tot = 0;
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        tot += a;
        mp[a]++;
    }

    if (tot % n != 0) {
        cout << "0\n";
        return 0;
    }
    tot /= n;

    int src = 0, sink = 0, zero = 0;
    set<pair<int, int>> usrc, usink;
    for (auto &p : mp) {
        if (p.first < tot) {
            src += p.second;
            usrc.insert(p);
        } else if (p.first > tot) {
            sink += p.second;
            usink.insert(p);
        } else {
            zero += p.second;
        }
    }

    M ret = choose(n, zero);
    n -= zero;
    DEBUG(n, zero, tot, usrc, usink, mp);
    if (usrc.size() > 1 && usink.size() == 1) {
        // more than one unique source
        // assert(!usink.empty());
        // if (usink.size() > 1) {
        //     cout << "0\n";
        //     return 0;
        // }
        if (usink.begin()->second != 1) {
            int tot = 0;
            ret = 1;
            for (auto &p : usrc) {
                tot += p.second;
                ret *= inv[p.second];
            }
            ret *= fact[tot] * 2;
        } else {
            ret *= fact[n];
            for (auto &p : usink)
                ret *= inv[p.second];
            for (auto &p : usrc)
                ret *= inv[p.second];
        }
    } else {
        usink.swap(usrc);
        if (usrc.size() > 1 && usink.size() == 1) {
            // more than one unique sink (swapped in code)
            // assert(!usink.empty());
            // if (usink.size() > 1) {
            //     cout << "0\n";
            //     return 0;
            // }
            if (usink.begin()->second != 1) {
                int tot = 0;
                ret = 1;
                for (auto &p : usrc) {
                    tot += p.second;
                    ret *= inv[p.second];
                }
                ret *= fact[tot] * 2;
            } else {
                ret *= fact[n];
                for (auto &p : usink)
                    ret *= inv[p.second];
                for (auto &p : usrc)
                    ret *= inv[p.second];
            }
        } else {
            if (usink.size() == 1 && usrc.size() == 1) {
                if (usink.begin()->second == 1 || usrc.begin()->second == 1) {
                    ret *= fact[n];
                    for (auto &p : usink)
                        ret *= inv[p.second];
                    for (auto &p : usrc)
                        ret *= inv[p.second];
                } else {
                    assert(usink.begin()->second > 1 && usrc.begin()->second > 1);
                    ret *= 2;
                }
            } else if (sink > 0 || src > 0) {
                ret *= fact[sink] * fact[src] * 2;
                for (auto &p : usink)
                    ret *= inv[p.second];
                for (auto &p : usrc)
                    ret *= inv[p.second];
            }
        }
    }
    cout << ret << "\n";

    return 0;
}