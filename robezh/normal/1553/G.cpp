#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int M = (int)1e6 + 5, N = (int)3e5 + 50;

int n, q;
int p[M];
int cmp[M + N], cmpcnt = 0;
bool vis[M + N];
vi G[M + N];
int a[N];
map<pii, int> have;

void dfs(int v, int cp) {
    vis[v] = true;
    cmp[v] = cp;

    for (int nxt : G[v]) {
        if(vis[nxt]) continue;
        dfs(nxt, cp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 1, M) p[i] = i;
    rep(i, 2, M) {
        if(p[i] != i) continue;
        for(int j = 2 * i; j < M; j += i) p[j] = i;
    }

    cin >> n >> q;
    rep(i, 0, n) {
        cin >> a[i];

    }
    rep(i, 0, n) {
        int x = a[i];
        while(x > 1) {
            int xp = p[x];
//            cout << x << " " << xp << endl;
            while(x % xp == 0) x /= xp;
//            cout << xp << " ";
            G[i].push_back(xp + n);
            G[xp + n].push_back(i);
        }
        cout << endl;
    }
    memset(cmp, -1, sizeof(cmp));
    rep(i, 0, n) {
        if(!vis[i]) dfs(i, cmpcnt++);
    }
//    rep(i, 0, n) cout << cmp[i] << " ";
//    cout << endl;
//
//    rep(i, 1, 10) cout << i << ": " << cmp[i + n] << " ";
//    cout << endl;

    rep(i, 0, n) {
        int x = a[i] + 1;
        vi ps;
        while(x > 1) {
            int xp = p[x];
            while(x % xp == 0) x /= xp;
            ps.push_back(xp);
        }
        x = a[i];
        while(x > 1) {
            int xp = p[x];
            while(x % xp == 0) x /= xp;
            ps.push_back(xp);
        }
        sort(all(ps));
        ps.resize(unique(all(ps)) - ps.begin());
//        cout << i << ":\n";
//        for(int x : ps) cout << x << " ";
//        cout << endl;
        rep(j, 0, sz(ps)) {
            rep(k, 0, j) {
                int u = cmp[ps[j] + n], v = cmp[ps[k] + n];
                if(u == -1 || v == -1) continue;
                if(u > v) swap(u, v);
                have[{u, v}] = 1;
//                cout << "have " << u << " " << v  << endl;
            }
        }
    }
    rep(i, 0, q) {
        int s, t;
        cin >> s >> t; s--, t--;
        int res = 2;
        if(cmp[s] == cmp[t]) res = 0;
        else {
            if (cmp[s] > cmp[t]) swap(s, t);
            if(have[{cmp[s], cmp[t]}]) res = 1;
        }
        cout << res << '\n';
    }


}