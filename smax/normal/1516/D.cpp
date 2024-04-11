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

const int MAX = 1e5 + 5;
const int LOG = 17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> lp(MAX);
    iota(lp.begin(), lp.end(), 0);
    for (int p=2; p<MAX; p++)
        if (lp[p] == p)
            for (int i=2*p; i<MAX; i+=p)
                lp[i] = p;

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    vector<int> last(MAX, n);
    vector<vector<int>> up(n + 1, vector<int>(LOG, n));
    for (int i=n-1; i>=0; i--) {
        int mn = up[i+1][0];
        vector<int> pf;
        while (a[i] > 1) {
            int p = lp[a[i]];
            mn = min(mn, last[p]);
            pf.push_back(p);
            while (a[i] % p == 0)
                a[i] /= p;
        }
        up[i][0] = mn;
        for (int p : pf)
            last[p] = i;
    }
    for (int j=1; j<LOG; j++)
        for (int i=0; i<n; i++)
            up[i][j] = up[up[i][j-1]][j-1];

    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ret = 1;
        for (int j=LOG-1; j>=0; j--)
            if (up[l][j] && up[l][j] <= r) {
                ret += 1 << j;
                l = up[l][j];
            }
        cout << ret << "\n";
    }

    return 0;
}