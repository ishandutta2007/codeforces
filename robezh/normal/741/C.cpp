#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
int a[N], b[N];
vi G[N];
int vis[N];

void dfs(int v, int c) {
    vis[v] = c;
    for(int nxt : G[v]) {
        if(vis[nxt] == -1) dfs(nxt, !c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i] >> b[i], a[i]--, b[i]--;
        G[2 * i].push_back(2 * i + 1);
        G[2 * i + 1].push_back(2 * i);
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    fill(vis, vis + 2 * n, -1);
    rep(i, 0, 2 * n) {
        if(vis[i] == -1) dfs(i, 0);
    }
    rep(i, 0, n) cout << vis[a[i]] + 1 << " " << vis[b[i]] + 1 << '\n';



}