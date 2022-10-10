#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
ll a[MAXN], pf[MAXN], sf[MAXN], uwur[MAXN], uwul[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        pf[i] = a[i] + pf[i - 1];
        if(a[i] != a[i - 1])
            uwul[i] = i;
        else
            uwul[i] = uwul[i - 1];
    }
    for(int i = n; i >= 1; i--) {
        sf[i] = a[i] + sf[i + 1];
        if(a[i] != a[i + 1])
            uwur[i] = i;
        else
            uwur[i] = uwur[i + 1];
    }
    ll ans = LLONG_MAX;
    ll p = 1;
    while(p <= n) {
        int q = uwur[p];
        if(q - p + 1 >= k) {
            ans = 0;
            break;
        }
        if(q >= k)
            ans = min(ans, (a[p] - 1)*(p - 1) - pf[p - 1] + k - (q - p + 1));
        if(n - p + 1 >= k)
            ans = min(ans, sf[q + 1] - (a[q] + 1)*(n - q) + k - (q - p + 1));
        ans = min(ans, (a[p] - 1)*(p - 1) - pf[p - 1] + sf[q + 1] - (a[q] + 1)*(n - q) + k - (q - p + 1));
        p = q + 1;
    }
    cout << ans << '\n';
}