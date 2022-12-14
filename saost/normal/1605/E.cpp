#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q, r, a[N], f[N], Q[N];
long long x, tt, sum[N];

void Init() {
    f[1] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=i*2; j<=n; j+=i) f[j] -= f[i], a[j] -= a[i];
        if (f[i]) Q[++r] = a[i] * f[i]; else tt += abs(a[i]);
    }
    sort(Q+1, Q+r+1);
    for(int i=1; i<=r; ++i) sum[i] = sum[i - 1] + Q[i];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    cin >> x;
    for(int i=2; i<=n; ++i) cin >> x, a[i] -= x;
    Init();
    cin >> q;
    while (q--) {
        cin >> x;
        int p = upper_bound(Q+1, Q+r+1, x) - Q - 1;
        long long ans = x * p - sum[p] + (sum[r] - sum[p]) - x * (r - p);
        cout << ans + tt << '\n';
    }
}