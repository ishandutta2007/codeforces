#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int l, ansL = 0, ansW = 0, w[100000];
long long s;
vector<int> adj[100000];

pair<pair<int, long long>, pair<long long, int>> dfs(int u) {
    pair<int, long long> minL(INT_MAX, LLONG_MAX);
    pair<long long, int> minW(LLONG_MAX, INT_MAX);
    for (int v : adj[u]) {
        auto p = dfs(v);
        if (p.first.first + 1 <= l && p.first.second + w[u] <= s)
            minL = min(minL, {p.first.first + 1, p.first.second + w[u]});
        if (p.second.first + w[u] <= s && p.second.second + 1 <= l)
            minW = min(minW, {p.second.first + w[u], p.second.second + 1});
    }
    if (minL.first == INT_MAX) {
        ansL++;
        minL = {1, w[u]};
    }
    if (minW.first == LLONG_MAX) {
        ansW++;
        minW = {w[u], 1};
    }
    return {minL, minW};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> l >> s;
    for (int i=0; i<n; i++) {
        cin >> w[i];
        if (w[i] > s) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i=1; i<n; i++) {
        int p;
        cin >> p;
        adj[p-1].push_back(i);
    }

    dfs(0);

    cout << min(ansL, ansW) << "\n";

    return 0;
}