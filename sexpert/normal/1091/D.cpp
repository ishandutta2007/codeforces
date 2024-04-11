#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
const ll MOD = 998244353;
ll prods[MAXN];

int main() {
    ll n;
    cin >> n;
    prods[0] = n;
    for(ll i = 1; i < n; i++) {
        prods[i] = (prods[i - 1]*(n - i))%MOD;
    }
    ll ans = (n * prods[n - 1])%MOD;
    ll sub = 0;
    for(ll i = 0; i < n - 1; i++) {
        sub = (sub + prods[i])%MOD;
    }
    ans = (ans - sub)%MOD;
    if(ans < 0)
        ans = (ans + MOD)%MOD;
    cout << ans << endl;
}