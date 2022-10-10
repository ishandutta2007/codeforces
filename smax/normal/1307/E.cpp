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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> posL(n), posR(n);
    for (int i=0; i<n; i++) {
        int s;
        cin >> s;
        s--;
        posL[s].push_back(i);
        posR[s].push_back(i);
    }
    for (auto &v : posR)
        reverse(v.begin(), v.end());

    vector<vector<int>> pref(n, vector<int>(n)), suff(n, vector<int>(n));
    for (int i=0; i<m; i++) {
        int f, h;
        cin >> f >> h;
        f--, h--;
        if (h < (int) posL[f].size()) {
            pref[f][posL[f][h]]++;
            suff[f][posR[f][h]]++;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=1; j<n; j++)
            pref[i][j] += pref[i][j-1];
        for (int j=n-2; j>=0; j--)
            suff[i][j] += suff[i][j+1];
    }

    auto combine = [&] (pair<int, M> &a, const pair<int, M> &b) -> void {
        if (a.first < b.first) {
            a.first = b.first;
            a.second = 0;
        }
        if (a.first == b.first)
            a.second += b.second;
    };

    pair<int, M> ret, last;
    for (int i=0; i<=n; i++) {
        pair<int, M> cur(0, 1), nxt(0, 1);
        for (int j=0; j<n; j++) {
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            if (i > 0)
                cnt1 += pref[j][i-1];
            if (i < n)
                cnt2 += suff[j][i];
            if (i + 1 < n)
                cnt3 += suff[j][i+1];
            if (cnt1 > 0) {
                int ways = cnt1 * cnt2 - min(cnt1, cnt2);
                if (ways > 0) {
                    cur.first += 2;
                    cur.second *= ways;
                } else {
                    cur.first++;
                    cur.second *= cnt1 + cnt2;
                }
            } else if (cnt2 > 0) {
                cur.first++;
                cur.second *= cnt2;
            }
            if (cnt1 > 0) {
                int ways = cnt1 * cnt3 - min(cnt1, cnt3);
                if (ways > 0) {
                    nxt.first += 2;
                    nxt.second *= ways;
                } else {
                    nxt.first++;
                    nxt.second *= cnt1 + cnt3;
                }
            } else if (cnt3 > 0) {
                nxt.first++;
                nxt.second *= cnt3;
            }
        }
        if (i > 0 && last.first == cur.first)
            cur.second -= last.second;
        combine(ret, cur);
        last = nxt;
    }
    cout << ret.first << " " << ret.second << "\n";

    return 0;
}