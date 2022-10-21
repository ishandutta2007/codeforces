#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50;

int n;
int h[N];
vi G[N];
int deg[N];
bool good[N];
ll sum[N];
int mxv[N][2];


void dfs(int v, int p, int add) {
    for(int nxt : G[v]) {
        if(!good[nxt] || nxt == p) continue;
        dfs(nxt, v, true);
        sum[v] += sum[nxt];
        int mx_nxt = mxv[nxt][0];
        rep(j, 0, 2) if(mx_nxt > mxv[v][j]) swap(mxv[v][j], mx_nxt);
    }
    if(add && h[v] > mxv[v][0]) {
        sum[v] += h[v] - mxv[v][0];
        mxv[v][0] = h[v];
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int mx = -1, mxcnt = 0, rt;
    rep(i, 0, n) {
        cin >> h[i];
        if(h[i] > mx) {
            mxcnt = 0;
            mx = h[i];
        }
        if(h[i] == mx) {
            mxcnt++;
            rt = i;
        }
    }
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> que;

    rep(i, 0, n) if(deg[i] == 1 && h[i] != mx) {
            que.push(i);
//            s[i] = {h[i], h[i]};
        }
    while(!que.empty()) {
        int v = que.front(); que.pop();
        good[v] = true;
//        cout << "vis " << v + 1 << endl;
        int tcnt = 0;
        for (int nxt : G[v]) {
            if(good[nxt]) continue;
            assert(++tcnt == 1);
            deg[nxt]--;
            if(deg[nxt] == 1 && h[nxt] != mx) {
                que.push(nxt);
            }
        }
    }

    if(mxcnt > 1) {
        ll res = 0;

        rep(i, 0, n) {
            if(good[i]) continue;
            dfs(i, -1, deg[i] == 1);
//            cout << i + 1 << " " << sum[i] << endl;
            res += sum[i];
        }

        cout << res << '\n';
    } else {
        dfs(rt, -1, false);
        ll res = sum[rt] + (h[rt] - mxv[rt][0]) + (h[rt] - mxv[rt][1]);
        cout << res << '\n';
    }


}