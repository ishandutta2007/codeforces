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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        set<int> st;
        vector<set<int>> adj(26);
        bool ok = true;
        for (int i=0; i<n; i++) {
            if (a[i] > b[i]) {
                ok = false;
                break;
            }
            if (a[i] < b[i]) {
                st.insert(a[i] - 'a');
                adj[a[i]-'a'].insert(b[i] - 'a');
            }
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }

        int ret = 0;
        while (!st.empty()) {
            int u = *st.begin(), v = *adj[u].begin();
            for (auto it=next(adj[u].begin()); it!=adj[u].end(); it++)
                adj[v].insert(*it);
            st.erase(u);
            if (!adj[v].empty())
                st.insert(v);
            ret++;
        }

        cout << ret << "\n";
    }

    return 0;
}