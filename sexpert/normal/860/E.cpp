#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> ii;

struct res {
    int son;
    ll count, answer;
};

const int MAXN = 5e5 + 5;
int h[MAXN], mh[MAXN];
int n, root;
ll preans[MAXN], fans[MAXN];
vector<int> adj[MAXN];
vector<ii> recover[MAXN];
map<int, res> ans[MAXN];

int dfs(int s, int p = 0) {
    h[s] = p ? h[p] + 1 : 0;
    mh[s] = h[s];
    for(auto &u : adj[s]) {
        mh[s] = max(mh[s], dfs(u, s));
        if(mh[u] > mh[adj[s][0]])
            swap(adj[s][0], u);
    }
    return mh[s];
}

void solve(int s) {
    if(adj[s].empty()) {
        ans[s][h[s]] = {s, 1, 0};
        return;
    }
    solve(adj[s][0]);
    swap(ans[adj[s][0]], ans[s]);
    ans[s][h[s]] = {s, 1, 0};
    for(int i = 1; i < adj[s].size(); i++) {
        int u = adj[s][i];
        solve(u);
        for(auto p : ans[u]) {
            int he = p.first;
            auto other = p.second;
            auto result = ans[s][he];
            result.answer += other.count * ((ll)(h[s] + 1));
            other.answer += result.count * ((ll)(h[s] + 1));
            result.count += other.count;
            recover[result.son].push_back({other.son, other.answer - result.answer});
            ans[s][he] = result;
        }
        ans[u].clear();
    }
}

void ppans(int s) {
    for(auto p : recover[s]) {
        preans[p.first] = preans[s] + p.second;
        ppans(p.first);
    }
}

void calc(int s, int p = 0) {
    fans[s] = fans[p] + h[s] + preans[s];
    for(auto v : adj[s]) calc(v, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x == 0)
            root = i;
        else
            adj[x].push_back(i);
    }
    dfs(root);
    solve(root);
    for(auto p : ans[root]) {
        auto result = p.second;
        preans[result.son] = result.answer;
        ppans(result.son);
    }
    calc(root);
    for(int i = 1; i <= n; i++)
        cout << fans[i] << " ";
    cout << '\n';
}