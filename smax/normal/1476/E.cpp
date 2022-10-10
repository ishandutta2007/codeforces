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

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> p(n);
    unordered_map<string, int> pos, in;
    for (int i=0; i<n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
        in[p[i]];
    }

    bool ok = true;
    unordered_map<string, vector<string>> adj;
    for (int i=0; i<m; i++) {
        string s;
        int mt;
        cin >> s >> mt;
        mt--;
        for (int j=0; j<k; j++)
            ok &= p[mt][j] == '_' || p[mt][j] == s[j];
        for (int mask=0; mask<1<<k; mask++) {
            string t(k, '_');
            for (int j=0; j<k; j++)
                if (mask & (1 << j))
                    t[j] = s[j];
            if (t != p[mt]) {
                in[t]++;
                adj[p[mt]].push_back(t);
            }
        }
    }
    if (!ok) {
        cout << "NO\n";
        return 0;
    }

    queue<string> q;
    for (auto &u : in)
        if (u.second == 0)
            q.push(u.first);

    vector<int> ret;
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        if (pos.count(u))
            ret.push_back(pos[u]);
        for (string &v : adj[u])
            if (--in[v] == 0)
                q.push(v);
    }
    if ((int) ret.size() < n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int x : ret)
        cout << x + 1 << " ";
    cout << "\n";

    return 0;
}