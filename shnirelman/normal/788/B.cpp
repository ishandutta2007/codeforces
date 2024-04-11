
#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
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
const int N = 1e6 + 1;

vector<int> g[N];
bool used[N];

void dfs(int v) {
    used[v] = true;

    for(auto u : g[v])
        if(!used[u])
            dfs(u);
}


void solve() {
    int n, m;
    cin >> n >> m;

    int a = 0;
    vector<int> deg(n, 0);
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;
        if(v != u) {
            g[v].push_back(u);
            g[u].push_back(v);
        } else
            a++;

        deg[v]++;
        deg[u]++;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(!used[i] && deg[i] > 0) {
            dfs(i);
            cnt++;
        }

    if(cnt > 1) {
        cout << 0 << endl;
        exit(0);
    }

    li ans = 0;
    for(int i = 0; i < n; i++) {
        ans += g[i].size() * 1ll * (g[i].size() - 1) / 2;
    }

    ans += a * 1ll * (m - a) + a * 1ll * (a - 1) / 2;

    cout << ans;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}