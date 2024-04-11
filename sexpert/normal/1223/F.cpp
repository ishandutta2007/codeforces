#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int nxt[300 * 1000 + 5], n;
ll dp[300 * 1000 + 5];
map<int, int> to[300 * 1000 + 5];
vector<int> v;

void handhold(int i) {
    if(v[i] == v[i + 1])
        nxt[i] = i + 1;
    else {
        if(nxt[i + 1] == -1 || to[i + 1].count(v[i]) == 0)
            nxt[i] = -1;
        else
            nxt[i] = to[i + 1][v[i]];
    }
    if(nxt[i] != -1 && nxt[i] < n - 1) {
        swap(to[i], to[nxt[i] + 1]);
        to[i][v[nxt[i] + 1]] = nxt[i] + 1;
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        nxt[i] = -1;
        to[i].clear();
        dp[i] = 0;
    }
    dp[n] = 0;
    v.assign(n, 0);
    for(auto &x : v)
        cin >> x;
    for(int i = n - 2; i >= 0; i--)
        handhold(i);
    //for(int i = 0; i < n; i++)
    //    cout << i << " -> " << nxt[i] << endl;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(nxt[i] == -1)
            continue;
        dp[i] = 1 + dp[nxt[i] + 1];
        ans += dp[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
}