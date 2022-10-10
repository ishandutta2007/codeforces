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

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

struct SuffixArray {
    const int ALPHA = 256;
    int n;
    string s;
    vector<int> p, lcp, inv;

    SuffixArray(const string &_s) : n((int) _s.length() + 1), s(_s), p(n), lcp(n-1), inv(n) {
        s += '$';
        buildSA();
        buildLCP();
        for (int i=0; i<n; i++)
            inv[p[i]] = i;
    }

    void buildSA() {
        vector<int> c(n), cnt(max(ALPHA, n));
        for (int i=0; i<n; i++)
            cnt[s[i]]++;
        for (int i=1; i<ALPHA; i++)
            cnt[i] += cnt[i-1];
        for (int i=0; i<n; i++)
            p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i=1; i<n; i++) {
            if (s[p[i]] != s[p[i-1]])
                classes++;
            c[p[i]] = classes - 1;
        }

        vector<int> pn(n), cn(n);
        for (int j=0; 1<<j<n; j++) {
            for (int i=0; i<n; i++) {
                pn[i] = p[i] - (1 << j);
                if (pn[i] < 0)
                    pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i=0; i<n; i++)
                cnt[c[pn[i]]]++;
            for (int i=1; i<classes; i++)
                cnt[i] += cnt[i-1];
            for (int i=n-1; i>=0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i=1; i<n; i++) {
                pair<int, int> cur(c[p[i]], c[(p[i] + (1 << j)) % n]), pre(c[p[i-1]], c[(p[i-1] + (1 << j)) % n]);
                if (cur != pre)
                    classes++;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
    }

    void buildLCP() {
        vector<int> rk(n);
        for (int i=0; i<n; i++)
            rk[p[i]] = i;

        int k = 0;
        for (int i=0; i<n; i++) {
            if (rk[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = p[rk[i] + 1];
            while (i + k < n && j + k < n && s[i+k] == s[j+k])
                k++;
            lcp[rk[i]] = k;
            if (k)
                k--;
        }
    }
};

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        string s, t;
        cin >> n >> m >> s >> t;

        int ptr = 0;
        for (char c : t) {
            while (ptr < n && s[ptr] != c)
                ptr++;
            ptr++;
        }
        if (ptr > n) {
            cout << "-1\n";
            continue;
        }

        SuffixArray sa(s + '#' + t), ra(string(s.rbegin(), s.rend()) + '#' + string(t.rbegin(), t.rend()));
        RMQ rmqS(sa.lcp), rmqR(ra.lcp);

        auto match = [&] (int i, int j, int len) -> int {
            int a = sa.inv[i], b = sa.inv[n+1+j];
            if (a > b)
                swap(a, b);
            return min(rmqS.query(a, b - 1), len);
            // int l = 1, r = min(len, n - i) + 1;
            // while (l < r) {
            //     int x = (l + r) / 2;
            //     if (hs(i, x) == ht(j, x))
            //         l = x + 1;
            //     else
            //         r = x;
            // }
            // return l - 1;
        };

        auto matchRev = [&] (int i, int j, int len) -> int {
            int a = ra.inv[n-i-1], b = ra.inv[n+1+m-j-1];
            if (a > b)
                swap(a, b);
            return min(rmqR.query(a, b - 1), len);
            // int l = 1, r = min(len, i + 1) + 1;
            // while (l < r) {
            //     int x = (l + r) / 2;
            //     if (hs(i - x + 1, x) == ht(j - x + 1, x))
            //         l = x + 1;
            //     else
            //         r = x;
            // }
            // return l - 1;
        };

        vector<int> reachL(m + 1), reachR(m + 1);
        for (int i=0, j=0; j<m; j++) {
            while (s[i] != t[j])
                i++;
            i++;
            reachL[j+1] = i;
        }
        for (int i=n-1, j=0; j<m; j++) {
            while (s[i] != t[m-j-1])
                i--;
            i--;
            reachR[j+1] = i;
        }

        int ret = INF;
        // pref is [0, i), suff is (i, n - 1]
        // cursor after index i has value i
        for (int i=0; i<=n; i++) {
            vector<int> matchL(m + 1, INF);
            matchL[0] = 2 * i;
            for (int j=0; j<m; j++) {
                DEBUG(j);
                if (reachL[j+1] > i)
                    break;
                DEBUG("match");
                int len = matchRev(i - 1, j, j + 1);
                DEBUG(len);
                matchL[j+1] = 2 * (i - len) - (j + 1 - len);
            }
            vector<int> matchR(m + 1, INF);
            matchR[0] = n - i;
            for (int j=0; j<m; j++) {
                DEBUG(j);
                if (reachR[j+1] < i)
                    break;
                DEBUG("match");
                int len = match(i, m - j - 1, j + 1);
                DEBUG(len);
                matchR[j+1] = n - i + len;
            }
            for (int j=0; j<=m; j++)
                ret = min(ret, matchL[j] + matchR[m-j] + (matchL[j] > 0));
            DEBUG(i, "done");
        }
        cout << ret << "\n";
    }

    return 0;
}