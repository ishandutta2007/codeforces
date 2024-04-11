#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

istream& operator >>(istream& cin, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
    return cin;
}

ostream& operator <<(ostream& cout, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    return cout;
}

const int M = 1e9 + 7;
const int N = 1e5 + 13;

vector<int> g[N];
ld dp[N];

void dfs(int v, int p) {
    dp[v] = 0;
    int cnt = 0;
    for(auto u : g[v])
        if(u != p) {
            dfs(u, v);
            dp[v] += dp[u] + 1;
            cnt++;
        }

    if(g[v].size() > 1)
        dp[v] /= cnt;

//    cout << v << ' ' << dp[v] << endl;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n -1 ; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;


        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, -1);

    cout << setprecision(20) << fixed << dp[0] << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}