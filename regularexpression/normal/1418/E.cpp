#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
const int M = 998244353;
int bpow(int a, int n){
    int res = 1;
    while(n > 0){
        if(n & 1){
            res = res * a % M;
        }
        a = a * a % M;
        n >>= 1;
    }
    return res;
}

int d[N], a[N], b[N], f[N], inv_f[N], pref[N];
int cnk(int n, int k){
    if(n < 0 || k < 0 || k > n){
        return 0;
    }
    return f[n] * inv_f[k] % M * inv_f[n - k] % M;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> d[i];
    }
    sort(d, d + n);
    for(int i = 0; i < n; ++i){
        pref[i + 1] = pref[i] + d[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
    }
    f[0] = inv_f[0] = 1;
    for(int i = 1; i <= n; ++i){
        f[i] = f[i - 1] * i % M;
        inv_f[i] = bpow(f[i], M - 2);
    }
    for(int i = 0; i < m; ++i){
        int cnt = lower_bound(d, d + n, b[i]) - d;
        int bad = n - cnt;
        int ans = 0;
        if(cnt > 0 && bad >= a[i]){
            ans += (bad - a[i] + 1) * cnk(n, bad + 1) % M * (pref[cnt] % M) % M * f[bad] % M * f[cnt - 1] % M;
            ans %= M;
        }
        if (cnt < n && bad > a[i]){
            int sum = pref[n] - pref[cnt];
            sum %= M;
            if(sum < 0){
                sum += M;
            }
            ans += (bad - a[i]) * cnk(n, bad) % M * sum % M * f[bad - 1] % M * f[cnt] % M;
            ans %= M;
        }
        cout << ans * inv_f[n] % M << '\n';
    }
    return 0;
}