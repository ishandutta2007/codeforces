#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

unordered_set<int> st, forbidden[300000];

void dfs(int u) {
    vector<int> pending;
    for (int v : st)
        if (!forbidden[u].count(v))
            pending.push_back(v);
    for (int v : pending)
        st.erase(v);
    for (int v : pending)
        dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    int numConnections = n - 1;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        forbidden[a].insert(b);
        forbidden[b].insert(a);
        if (a == 0 || b == 0)
            numConnections--;
    }
    if (numConnections < k) {
        cout << "impossible\n";
        return 0;
    }

    int comp = 0;
    for (int i=1; i<n; i++)
        st.insert(i);
    for (int i=1; i<n; i++)
        if (st.count(i) && !forbidden[0].count(i)) {
            comp++;
            dfs(i);
        }

    if (st.empty() && comp <= k)
        cout << "possible\n";
    else
        cout << "impossible\n";

    return 0;
}