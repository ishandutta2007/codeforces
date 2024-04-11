#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
const ll MOD = 998244353;
ll p10[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p10[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p10[i] = (10LL * p10[i - 1]) % MOD;
    int n;
    cin >> n;
    for(int k = 1; k <= n; k++) {
        if(k == n)
            cout << "10\n";
        else {
            ll ans = (180LL * p10[n - k - 1]) % MOD;
            if(k < n - 1)
                ans = (ans + ((ll)(n - k - 1) * 810LL * p10[n - k - 2])) % MOD;
            cout << ans << " ";
        }
    }
}