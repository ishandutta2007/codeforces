#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

int n, k;
vector<int> G[N], H[N];
int head[N];
int nxt[N];
vi res;
int ord[N], comp[N], ccnt = 0;
int in[N];
vi cps[N];

void dfs(int v, int c, int rk) {
    comp[v] = c;
    ord[v] = rk;
    cps[c].push_back(v);
    if(nxt[v] != -1) dfs(nxt[v], c, rk + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    memset(nxt, -1, sizeof(nxt));
    rep(i, 0, n) {
        int p; cin >> p; p--;
        if(p == -1) continue;
        G[p].push_back(i);
    }
    fill(head, head + n, 1);
    rep(i, 0, k) {
        int a, b; cin >> a >> b; a--, b--;
        nxt[a] = b;
        head[b] = 0;
    }
    rep(i, 0, n) if(head[i]) dfs(i, ccnt++, 0);

//    cout << ccnt << endl;
//    rep(i, 0, ccnt) {
//        for(int x : cps[i]) cout << x + 1 << " ";
//        cout << endl;
//    }
    rep(i, 0, n) {
        for(int x : G[i]) {
            if(comp[i] == comp[x]) {
                if(ord[i] > ord[x]) {
//                    cout << i + 1 << " to " << x + 1 << endl;
                    return cout << "0\n", 0;

                }
            }
            else {
                H[comp[i]].push_back(comp[x]);
                in[comp[x]]++;
            }
        }
    }

    queue<int> que;
    rep(i, 0, ccnt) {
        if(in[i] == 0) {
            for(int v : cps[i]) res.push_back(v);
            que.push(i);
        }
    }
    while(!que.empty()) {
        int ci = que.front(); que.pop();
        for(int nx : H[ci]) {
            in[nx]--;
            if(in[nx] == 0) {
                for(int v : cps[nx]) res.push_back(v);
                que.push(nx);
            }
        }
    }
    if(sz(res) != n) return cout << "0\n", 0;
    rep(i, 0, n) cout << res[i] + 1 << " ";
    cout << '\n';
}