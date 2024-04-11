#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll binom[2005][2005], fac[2005], perm[2005], fixable, neg;
bool taken[2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = binom[0][0] = 1;
    for(int i = 1; i < 2005; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        binom[i][0] = binom[i][i] = 1;
    }

    for(int i = 1; i < 2005; i++) {
        for(int j = 1; j < 2005; j++)
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;
    }

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        perm[i] = x;
        if(x == -1) neg++;
        else taken[x] = true;
    }
    for(int i = 1; i <= n; i++)
        if(perm[i] == -1 && !taken[i]) fixable++;
    ll ans = 0, sgn = 1;
    for(ll k = 0; k <= fixable; k++) {
        ans = (ans + binom[fixable][k] * fac[neg - k] * sgn) % MOD;
        sgn *= -1;
    }
    if(ans < 0)
        ans += MOD;
    cout << ans << endl;
}