#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, INF = (int)1e9;
const double EPS = 1e-5;

int n, m;
int sq;
vector<int> G[N];
stack<int> S;
int vis[N], dep[N];
vector<int> is;
int in[N];

void dfs(int v, int p, int d) {
    dep[v] = d;
    vis[v] = 1;
    S.push(v);

    vector<int> back;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        if(vis[nxt]) {
            back.push_back(nxt);
            if(dep[nxt] + sq - 1 <= dep[v]) {
                vector<int> res;
                while(true) {
                    res.push_back(S.top()); S.pop();
                    if(res.back() == nxt) {
                        cout << "2\n" << res.size() << "\n";
                        for(int x : res) cout << x + 1 << " ";
                        cout << "\n";
                        exit(0);
                    }
                }
            }
        }
        else {
            dfs(nxt, v, d + 1);
        }
    }
    if(in[v]) {
        if(p != -1) in[p] = 0;
        is.push_back(v);
        for(int to : back) in[to] = 0;
    }
    S.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    fill(in, in + n, 1);
    sq = (int)(ceil(sqrt(n) - EPS));
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1, 0);
    cout << "1\n";
    assert(is.size() >= sq);
    for(int i = 0; i < sq; i++) cout << is[i] + 1 << " ";
    cout << '\n';

}