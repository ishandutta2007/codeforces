#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)5e5 + 50;

int n, m;
vi G[N];
int dep[N];
int vis[N];

void dfs(int v) {
    vis[v] = 1;
    dep[v] = 0;
    for(int nxt : G[v]) {
        if(vis[nxt]) continue;
        dfs(nxt);
        dep[v] = max(dep[v], dep[nxt] + 1);
    }
}

vi path;

void trace(int v) {
    vis[v] = 1;
    path.push_back(v);
    if(dep[v] == 0) return ;
    for(int nxt : G[v]) {
        if(vis[nxt]) continue;
        if(dep[nxt] + 1 == dep[v]) {
            trace(nxt);
            return ;
        }
    }
}

vector<int> vs[N];
vector<pii> prs;

int solve(int v) {
    vis[v] = 1;
    vector<int> xs;
    for(int nxt : G[v]) {
        if(vis[nxt]) continue;
        xs.push_back(solve(nxt));
    }
    priority_queue<pii> pque;
    for(int x : xs) pque.push({sz(vs[x]), x});
    int last = -1;
    while(sz(pque) >= 2) {
        pii p1 = pque.top(); pque.pop();
        pii p2 = pque.top(); pque.pop();
        prs.push_back({vs[p1.second].back(), vs[p2.second].back()});
        vs[p1.second].pop_back();
        vs[p2.second].pop_back();
        p1.first--, p2.first--;
        if(p1.first) pque.push(p1);
        if(p2.first) pque.push(p2);
    }
    if(sz(pque)) last = pque.top().second;
    if(last == -1) last = v;
    vs[last].push_back(v);
//    cout << v << " " << last << endl;
    return last;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) G[i].clear();
        rep(i, 0, m) {
            int a, b; cin >> a >> b; a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        fill(vis, vis + n, 0);
        dfs(0);
        if((dep[0] + 1) * 2 >= n) {
            cout << "PATH\n";
            path.clear();
            fill(vis, vis + n, 0);
            trace(0);
            cout << sz(path) << '\n';
            for(int p : path) cout << p + 1 << " ";
            cout << '\n';
        } else {
            prs.clear();
            fill(vis, vis + n, 0);

            rep(i, 0, n) vs[i].clear();
            solve(0);
            cout << "PAIRING\n";
            cout << sz(prs) << '\n';
            for(pii p : prs) cout << p.first + 1 << " " << p.second + 1 << '\n';
        }
    }
}