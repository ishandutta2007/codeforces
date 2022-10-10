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

template<int ALPHA>
struct SuffixAutomaton {
    int last;
    vector<int> len, link;
    vector<long long> cnt;
    vector<array<int, ALPHA>> nxt;

    SuffixAutomaton() : last(0), len(1), link(1, -1), cnt(1), nxt(1) {}

    SuffixAutomaton(const string &s) : SuffixAutomaton() {
        for (char c : s)
            extend(c);
    }

    int getIndex(char c) {
        return c - 'a';
    }

    void extend(char c) {
        int cur = (int) len.size(), i = getIndex(c), p = last;
        len.push_back(len[last] + 1);
        link.emplace_back();
        cnt.push_back(1);
        nxt.emplace_back();
        while (p != -1 && !nxt[p][i]) {
            nxt[p][i] = cur;
            p = link[p];
        }
        if (p != -1) {
            int q = nxt[p][i];
            if (len[p] + 1 == len[q]) {
                link[cur] = q;
            } else {
                int clone = (int) len.size();
                len.push_back(len[p] + 1);
                link.push_back(link[q]);
                cnt.push_back(0);
                nxt.push_back(nxt[q]);
                while (p != -1 && nxt[p][i] == q) {
                    nxt[p][i] = clone;
                    p = link[p];
                }
                link[q] = link[cur] = clone;
            }
        }
        last = cur;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    string s;
    cin >> s >> q;
    int n = (int) s.size();

    SuffixAutomaton<26> sa(s);
    int o = (int) sa.len.size();
    vector<vector<int>> nodes(n + 1);
    for (int u=1; u<o; u++)
        nodes[sa.len[u]].push_back(u);
    for (int i=n; i>0; i--)
        for (int u : nodes[i])
            sa.cnt[sa.link[u]] += sa.cnt[u];

    while (q--) {
        string x;
        cin >> x;
        int m = (int) x.size();
        x += x;
        PolyHash hs(x);

        int u = 0, l = 0;
        for (int i=0; i<m-1; i++) {
            while (u != -1 && !sa.nxt[u][x[i]-'a']) {
                u = sa.link[u];
                l = sa.len[u];
            }
            if (u == -1) {
                u = l = 0;
            } else {
                u = sa.nxt[u][x[i]-'a'];
                l++;
            }
        }
        long long ret = 0;
        unordered_set<ull> st;
        for (int i=m-1; i<(int)x.size()-1; i++) {
            while (u != -1 && !sa.nxt[u][x[i]-'a']) {
                u = sa.link[u];
                l = sa.len[u];
            }
            if (u == -1) {
                u = l = 0;
            } else {
                u = sa.nxt[u][x[i]-'a'];
                l++;
                while (m <= sa.len[sa.link[u]]) {
                    u = sa.link[u];
                    l = sa.len[u];
                }
                if (m <= l && !st.count(hs(i - m + 1, m)))
                    ret += sa.cnt[u];
            }
            st.insert(hs(i - m + 1, m));
        }
        cout << ret << "\n";
    }

    return 0;
}