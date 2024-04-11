#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e5 + 5;
int n, res, lft[N], rgt[N], dp[N];
long long d_cnt[N];
vector<int> S[N];

void Enter() {
    cin >> n;
    FOR(i, 2, n) {
        int u; cin >> u;
        S[u].push_back(i);
    }
    FOR(i, 1, n) cin >> lft[i] >> rgt[i];
}

void DFS(int u) {
    for(int v : S[u]) {
        DFS(v);
        d_cnt[u] += d_cnt[v];
        dp[u] += dp[v];
    }
    if (d_cnt[u] < lft[u]) {
        ++dp[u];
        d_cnt[u] = rgt[u];
    }
    d_cnt[u] = min(d_cnt[u], (long long)rgt[u]);
}

void Process() {
    DFS(1);
    cout << dp[1] << '\n';
}

void Reset() {
    FOR(i, 1, n) S[i].clear(), dp[i] = d_cnt[i] = 0;
}

int main()
{
    #define file ""
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if (fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    int t; cin >> t;
    while (t--) {
        Enter();
        Process();
        Reset();
    }
}