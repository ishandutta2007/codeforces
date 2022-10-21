#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what_is(x) cerr << #x << " is " << x << endl;
const int N = (int)2e5 + 50;

priority_queue<pii> pque;
vi G[N];
int n, k;
int par[N], sub[N], ori[N], dep[N];
int in[N];
ll fres = 0;

void dfs(int v, int p, int d) {
    par[v] = p;
    sub[v] = 1;
    dep[v] = d;
    for(int nxt : G[v]) {
        if (nxt == p) continue;
        dfs(nxt, v, d + 1);
        sub[v] += sub[nxt];
    }
    ori[v] = sub[v];
    if(sub[v] == 1) pque.push({dep[v], v});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1, 0);
    while(k > 0) {
        k--;
        auto p = pque.top(); pque.pop();
        in[p.second] = 1;
        fres += p.first;
        if(par[p.second] != -1) {
            int px = par[p.second];
            sub[px] -= ori[p.second];
            if(sub[px] == 1) {
                pque.push({dep[px] - (ori[px] - 1), par[p.second]});
            }
        }
    }
    cout << fres << endl;
}