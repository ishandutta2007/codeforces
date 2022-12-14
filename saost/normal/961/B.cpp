#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long t, n, k, a[N], b[N], c[N], f[N], res;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<=n; ++i) f[i] = f[i-1] + a[i] * b[i], c[i] = c[i-1] + a[i];
    for(int i=k; i<=n; ++i) res = max(res, f[i-k] + c[i] - c[i-k] + f[n] - f[i]);
    cout << res;
}