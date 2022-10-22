#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll a[1000002];
ll p[1000002];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    p[0] = 1;
    for(int i = 1; i < n; i++) p[i] = p[i - 1] * 2 % MOD;
    ll s = 0, ans = 0;
    for(int i = 1; i < n; i++){
        s = (s + a[i] * p[n - i - 1]) % MOD;
        ans = (ans + s) % MOD;
    }
    s = s * 2 % MOD;
    s = (s + a[n] * p[0]) % MOD;
    ans = (ans + s) % MOD;
    cout << ans << endl;
}