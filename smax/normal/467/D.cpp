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

#define MAXN 200000

int id = 0, sccCount = 0, dfsNum[MAXN], dfsLow[MAXN];
bool visited[MAXN] = {};
vector<int> adj[MAXN];
stack<int> s;

void dfs(int u) {
    dfsNum[u] = dfsLow[u] = id++;
    s.push(u);
    visited[u] = true;
    for (int v : adj[u]) {
        if (dfsNum[v] == -1)
            dfs(v);
        if (visited[v])
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    }

    if (dfsLow[u] == dfsNum[u]) {
        int v = -1;
        while (u != v) {
            v = s.top();
            s.pop();
            visited[v] = false;
            dfsLow[v] = sccCount;
        }
        sccCount++;
    }
}

int idx = 0, rCnt[MAXN] = {}, len[MAXN];
pair<int, int> best[MAXN], dp[MAXN];
string essay[MAXN];
unordered_set<int> dag[MAXN];
unordered_map<string, int> encode;

pair<int, int> solve(int u) {
    if (dp[u].second != -1)
        return dp[u];

    dp[u] = best[u];
    for (int v : dag[u])
        dp[u] = min(dp[u], solve(v));

    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> essay[i];
        transform(essay[i].begin(), essay[i].end(), essay[i].begin(), ::tolower);
    }

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string x, y;
        cin >> x >> y;

        transform(x.begin(), x.end(), x.begin(), ::tolower);
        transform(y.begin(), y.end(), y.begin(), ::tolower);
        if (!encode.count(x)) {
            encode[x] = idx;
            for (char c : x)
                if (c == 'r')
                    rCnt[idx]++;
            len[idx++] = x.length();
        }
        if (!encode.count(y)) {
            encode[y] = idx;
            for (char c : y)
                if (c == 'r')
                    rCnt[idx]++;
            len[idx++] = y.length();
        }
        adj[encode[x]].push_back(encode[y]);
    }

    memset(dfsNum, -1, sizeof(dfsNum));
    for (int i=0; i<idx; i++)
        if (dfsNum[i] == -1)
            dfs(i);

    for (int i=0; i<sccCount; i++)
        best[i] = dp[i] = {INT_MAX, -1};
    for (int u=0; u<idx; u++) {
        best[dfsLow[u]] = min(best[dfsLow[u]], {rCnt[u], len[u]});
        for (int v : adj[u])
            if (dfsLow[u] != dfsLow[v])
                dag[dfsLow[u]].insert(dfsLow[v]);
    }

    for (int i=0; i<sccCount; i++)
        solve(i);

    long long retR = 0, retLen = 0;
    for (int i=0; i<m; i++) {
        pair<int, int> p{0, essay[i].length()};
        for (char c : essay[i])
            if (c == 'r')
                p.first++;
        if (encode.count(essay[i]))
            p = min(p, dp[dfsLow[encode[essay[i]]]]);
        retR += p.first;
        retLen += p.second;
    }

    cout << retR << " " << retLen << "\n";

    return 0;
}