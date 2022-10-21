#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

int n, m;
int p[N];
int cnt[N];
int to[N];
int vis[N];

int dfs(int v) {
    vis[v] = 1;
    if(!vis[to[v]]) return dfs(to[v]) + 1;
    return 1;
}

bool check(int sf) {
    fill(vis, vis + n, 0);
    rep(i, 0, n) {
        to[i] = (p[i] + sf + n) % n;
    }
    int res = 0;
    rep(i, 0, n) {
        if(!vis[i]) res += dfs(i) - 1;
    }
    return res <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) {
            cin >> p[i]; p[i]--;
        }
        fill(cnt, cnt + n, 0);
        rep(i, 0, n) cnt[(i - p[i] + n) % n]++;
        vi vs;
        rep(i, 0, n) if(cnt[i] >= n - 2 * m) vs.push_back(i);
//        cout << sz(vs) << "\n";
//        for (int r : vs) cout << r << " ";
//        cout << endl;
        vi rs;
        for (int v : vs) {
            if(check(v)) rs.push_back(v);
        }
        cout << sz(rs) << " ";
        for (int r : rs) cout << r << " ";
        cout << '\n';
    }

}