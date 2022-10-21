#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
const int N = 3005;
const ll INF = (ll)1e18;

void upd(P &p1, P p2) {
    if(p2.first > p1.first || (p2.first == p1.first && p2.second > p1.second)) p1 = p2;
}

int n, m;
P dp[N][N];
P newdp[N];
int sub[N];
vector<int> G[N];
int val[N];

void merge(int v, int u) {
    for(int i = 1; i <= sub[u] + sub[v]; i++) newdp[i] = {-INF, -INF};
    for(int i = 1; i <= sub[v]; i++) {
        for(int j = 1; j <= sub[u]; j++) {
            upd(newdp[i + j - 1], {dp[v][i].first + dp[u][j].first, dp[v][i].second + dp[u][j].second});
            upd(newdp[i + j], {dp[v][i].first + dp[u][j].first + (dp[u][j].second > 0),
                               dp[v][i].second});
        }
    }
    sub[v] += sub[u];
    for(int i = 1; i <= sub[v]; i++) dp[v][i] = newdp[i];
}

void calc(int v, int p) {
    sub[v] = 1;
    dp[v][1] = {0, val[v]};
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        calc(nxt, v);
        merge(v, nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < n; i++) {
            cin >> val[i];
        }
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            val[i] = x - val[i];
        }
        for(int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b; a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        calc(0, -1);
//        cout << sub[0] << endl;
        cout << (dp[0][m].first + (dp[0][m].second > 0)) << '\n';
    }
}