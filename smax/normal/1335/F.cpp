#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

unordered_map<char, pair<int, int>> mp{{'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}};
vector<string> c, s;
vector<int> cnt;
vector<vector<bool>> visitedCycle, visitedBlack;
vector<pair<int, int>> cycle;
vector<vector<vector<pair<int, int>>>> adj;

pair<int, int> nxt(int i, int j) {
    return {i + mp[s[i][j]].first, j + mp[s[i][j]].second};
}

void dfsCycle(int i, int j) {
    if (visitedCycle[i][j]) {
        cycle.emplace_back(i, j);
        return;
    }

    visitedCycle[i][j] = true;
    auto p = nxt(i, j);
    dfsCycle(p.first, p.second);
    if (cycle.back() == p && cycle[0] != make_pair(i, j))
        cycle.emplace_back(i, j);
}

void dfsBlack(int i, int j, int d = 0) {
    if (visitedBlack[i][j])
        return;

    visitedBlack[i][j] = true;
    if (c[i][j] == '0')
        cnt[d % cycle.size()]++;
    for (auto p : adj[i][j])
        dfsBlack(p.first, p.second, d + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        c.resize(n);
        s.resize(n);
        visitedCycle.assign(n, vector<bool>(m));
        visitedBlack.assign(n, vector<bool>(m));
        adj.assign(n, vector<vector<pair<int, int>>>(m, vector<pair<int, int>>()));
        for (int i=0; i<n; i++)
            cin >> c[i];
        for (int i=0; i<n; i++)
            cin >> s[i];

        int ret = 0, black = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                auto p = nxt(i, j);
                adj[p.first][p.second].emplace_back(i, j);
            }

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (!visitedBlack[i][j]) {
                    cycle.clear();
                    dfsCycle(i, j);
                    ret += cycle.size();
                    cnt.assign(cycle.size(), 0);
                    dfsBlack(cycle[0].first, cycle[0].second);
                    for (int x : cnt)
                        black += (x > 0);
                }

        cout << ret << " " << black << "\n";
    }

    return 0;
}