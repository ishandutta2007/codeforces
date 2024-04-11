#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll mem[505][505][2];
int adj[505][505];
int n;

ll dp(int i, int j, int b) {
    if(j == 0)
        return 1;
    if(j == 1)
        return (b ? adj[i][(i + 1) % n] : 1);
    if(mem[i][j][b] != -1)
        return mem[i][j][b];
    ll res = (b ? 0 : dp((i + 1) % n, j - 1, 1));
    for(int k = j - 1 + b; k >= 1; k--) {
        if(adj[i][(i + k) % n]) {
            res = (res + dp(i, k, 0) * dp((i + k) % n, j - k, b)) % MOD;
        }
    }
    return mem[i][j][b] = res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    memset(mem, -1, sizeof mem);
    ll ans = 0;
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n ; j++) {
            cout << dp(i, j, 0) << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n ; j++) {
            cout << dp(i, j, 1) << " ";
        }
        cout << endl;
    }*/
    for(int k = 1; k <= n - 1; k++) {
        if(adj[0][k])
            ans = (ans + dp(1, k - 1, 1) * dp(k, n - k, 0)) % MOD;
    }
    cout << ans << '\n';
}