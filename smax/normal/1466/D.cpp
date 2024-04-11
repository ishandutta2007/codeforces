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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> w(n);
        long long ret = 0;
        for (int i=0; i<n; i++) {
            cin >> w[i].first;
            w[i].second = i;
            ret += w[i].first;
        }
        vector<int> deg(n);
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            deg[u]++;
            deg[v]++;
        }

        sort(w.rbegin(), w.rend());
        int i = 0;
        cout << ret << " ";
        for (int k=2; k<n; k++) {
            while (i < n && deg[w[i].second] <= 1)
                i++;
            if (i < n) {
                ret += w[i].first;
                deg[w[i].second]--;
            }
            cout << ret << " ";
        }
        cout << "\n";
    }

    return 0;
}