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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n), cnt(1 << n);
    for (int i=n-1; i>=0; i--)
        cin >> w[i];
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        int x = 0;
        for (char c : s)
            x = 2 * x + int(c - '0');
        cnt[x]++;
    }

    vector<int> val(1 << n);
    for (int x=0; x<1<<n; x++)
        for (int i=0; i<n; i++)
            if (~x & (1 << i))
                val[x] += w[i];

    vector<vector<pair<int, int>>> sorted(1 << n);
    for (int x=0; x<1<<n; x++) {
        for (int y=0; y<1<<n; y++)
            sorted[x].emplace_back(val[x ^ y], cnt[y]);
        sort(sorted[x].begin(), sorted[x].end());
        for (int i=1; i<1<<n; i++)
            sorted[x][i].second += sorted[x][i-1].second;
    }

    for (int i=0; i<q; i++) {
        string t;
        int k;
        cin >> t >> k;
        int x = 0;
        for (char c : t)
            x = 2 * x + int(c - '0');
        auto it = upper_bound(sorted[x].begin(), sorted[x].end(), make_pair(k, INT_MAX));
        cout << (it == sorted[x].begin() ? 0 : prev(it)->second) << "\n";
    }

    return 0;
}