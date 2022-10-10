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

int a[200005], ret[200005];
vector<pair<int, int>> in[200005], out[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        in[l].emplace_back(x, i);
        out[r].emplace_back(x, i);
    }

    memset(ret, -1, sizeof(ret));
    map<int, set<int>> mp;
    for (int i=0; i<n; i++) {
        for (auto [x, j] : in[i])
            mp[x].insert(j);
        vector<int> pending;
        for (auto &[x, st] : mp)
            if (x != a[i]) {
                for (int j : st)
                    ret[j] = i + 1;
                pending.push_back(x);
            }
        for (int x : pending)
            mp.erase(x);
        for (auto [x, j] : out[i])
            if (mp.count(x))
                mp[x].erase(j);
    }

    for (int i=0; i<m; i++)
        cout << ret[i] << "\n";

    return 0;
}