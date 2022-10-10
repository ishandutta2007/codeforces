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

#define MAXN 100005

int v[MAXN], l[MAXN], r[MAXN];
bool isNotRoot[MAXN];
set<int> success;
multiset<int> lst, rst;

void dfs(int u) {
    if (u == -1)
        return;
    if ((lst.empty() || v[u] < *lst.begin()) && (rst.empty() || v[u] > *rst.rbegin()))
        success.insert(v[u]);
    lst.insert(v[u]);
    dfs(l[u]);
    lst.erase(lst.find(v[u]));
    rst.insert(v[u]);
    dfs(r[u]);
    rst.erase(rst.find(v[u]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i] >> l[i] >> r[i];
        isNotRoot[l[i]] = isNotRoot[r[i]] = true;
    }

    int u = 1;
    while (isNotRoot[u])
        u++;
    dfs(u);

    int ret = n;
    for (int i=1; i<=n; i++)
        if (success.count(v[i]))
            ret--;

    cout << ret << "\n";

    return 0;
}