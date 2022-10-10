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

const int MAX = 1e5 + 5;
const int SZ = 320;

int par[MAX], cnt[MAX];

int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    par[v] = u;
    cnt[u] += cnt[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    vector<int> t(m), l(m), r(m), x(m);
    for (int i=0; i<m; i++) {
        cin >> t[i] >> l[i] >> r[i] >> x[i];
        l[i]--, r[i]--;
    }

    vector<int> ret(m);
    for (int bl=0; bl<n; bl+=SZ) {
        int br = min(bl + SZ, n) - 1;
        for (int i=0; i<MAX; i++) {
            par[i] = i;
            cnt[i] = 0;
        }
        for (int i=bl; i<=br; i++)
            cnt[a[i]]++;
        int mn = 0, mx = MAX - 1;
        for (int i=0; i<m; i++) {
            if (t[i] == 1) {
                if (l[i] <= bl && br <= r[i]) {
                    if (2 * x[i] <= mx - mn) {
                        for (int j=mn+1; j<=mn+x[i]; j++)
                            unite(j + x[i], j);
                        mn += x[i];
                    } else if (mn + x[i] + 1 <= mx) {
                        for (int j=mn+x[i]+1; j<=mx; j++)
                            unite(j - x[i], j);
                        mx = mn + x[i];
                    }
                } else {
                    for (int j=max(bl,l[i]); j<=min(br,r[i]); j++) {
                        a[j] = find(a[j]);
                        if (a[j] - x[i] > mn) {
                            cnt[a[j]]--;
                            a[j] = find(a[j] - x[i]);
                            cnt[a[j]]++;
                        }
                    }
                }
            } else {
                if (l[i] <= bl && br <= r[i]) {
                    ret[i] += x[i] <= mx - mn ? cnt[mn+x[i]] : 0;
                } else {
                    for (int j=max(bl,l[i]); j<=min(br,r[i]); j++) {
                        a[j] = find(a[j]);
                        if (a[j] - mn == x[i])
                            ret[i]++;
                    }
                }
            }
        }
    }

    for (int i=0; i<m; i++)
        if (t[i] == 2)
            cout << ret[i] << "\n";

    return 0;
}