#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
int deg[MAXN], w[MAXN];

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        deg[i] = 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    priority_queue<int> q;
    for(int i = 1; i <= n; i++) {
        ans += w[i];
        for(int j = 0; j < deg[i] - 1; j++)
            q.push(w[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        cout << ans << " ";
        if(i < n - 2)
            ans += q.top(); q.pop();
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}