#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll Mod = 998244353;
const int N = 15e4 + 3;

int a[2 * N];
int n;

ll fast_pow(ll base, ll exp){
    if(!exp) return 1;
    if(exp & 1) return base * fast_pow(base, exp ^ 1) % Mod;

    ll t = fast_pow(base, exp >> 1);
    return t * t % Mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for(int i = 0; i < 2 * n; ++i)
        cin >> a[i];

    sort(a, a + 2 * n);

    long long ans = 0;
    for(int i = 0; i < 2 * n; ++i){
        if(i < n) ans -= a[i];
        else ans += a[i];
    }
    ans %= Mod;

    for(ll i = 2 * n; i > n; --i){
        ans *= i;
        if(ans >= Mod) ans %= Mod;
    }

    ll d = 1;
    for(ll i = 1; i <= n; ++i){
        d *= i;
        if(d >= Mod) d %= Mod;
    }

    ans *= fast_pow(d, Mod - 2);
    ans %= Mod;

    cout << ans << "\n";
}