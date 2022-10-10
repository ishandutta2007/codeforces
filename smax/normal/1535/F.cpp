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

const int SZ = 500;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> s(n);
    unordered_map<string, vector<int>> mp;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        string sorted = s[i];
        sort(sorted.begin(), sorted.end());
        mp[sorted].push_back(i);
    }

    long long ret = 0, cur = 0;
    for (const auto &p : mp) {
        ret += p.second.size() * cur * 1337;
        cur += p.second.size();
        if (p.second.size() <= SZ * s[0].size()) {
            for (int i : p.second)
                for (int j : p.second)
                    if (i < j) {
                        int l = 0, r = (int) s[i].size() - 1;
                        while (s[i][l] == s[j][l])
                            l++;
                        while (s[i][r] == s[j][r])
                            r--;
                        ret += is_sorted(s[i].begin() + l, s[i].begin() + r + 1) || is_sorted(s[j].begin() + l, s[j].begin() + r + 1) ? 1 : 2;
                    }
        } else {
            long long tot = (long long) p.second.size() * (p.second.size() - 1) / 2;
            unordered_set<ull> st;
            for (int i : p.second)
                st.insert(PolyHash(s[i])(0, (int) s[i].size()));
            for (int i : p.second) {
                for (int l=0; l<(int)s[i].size(); l++)
                    for (int r=l+1; r<(int)s[i].size(); r++) {
                        string temp = s[i];
                        sort(temp.begin() + l, temp.begin() + r + 1);
                        if (s[i][l] != temp[l] && s[i][r] != temp[r] && st.count(PolyHash(temp)(0, (int) s[i].size()))) {
                            tot--;
                            ret++;
                        }
                    }
            }
            ret += 2 * tot;
        }
    }
    cout << ret << "\n";

    return 0;
}