#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;
const ld E13 = (ld)1e14 + 50;

int n;
vector<int> G[N];
int num[N];
ld lcm[N];
ll dp[N], sum = 0;
ll res = 0;

void dfs(int v, int p) {
    bool leaf = true;
    lcm[v] = 1;
    dp[v] = 0;
    ll mn = INF;
    int cnt = 0;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        leaf = false;
        dfs(nxt, v);
        cnt++;
        mn = min(mn, dp[nxt]);
        ld mul = lcm[nxt] / __gcd((ll)lcm[v], (ll)lcm[nxt]);
        if(mul * lcm[v] > E13) {
            cout << sum << endl;
            exit(0);
        }
        lcm[v] *= mul;
    }
    if(leaf) {
        lcm[v] = 1, dp[v] = num[v];
        return ;
    }
    ll rem = mn / (ll)lcm[v];
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        res += dp[nxt] - rem * (ll)lcm[v];
        dp[v] += rem * (ll)lcm[v];
    }
    lcm[v] *= cnt;
    if(lcm[v] > E13) {
        cout << sum << endl;
        exit(0);
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    cout << res << endl;
}