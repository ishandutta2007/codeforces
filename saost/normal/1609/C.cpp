#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
int t, n, e, f[1000005], a[N], L[N], R[N];
long long res;

void eratos() {
    f[1] = 1;
    for(int i=2; i*i<1000001; ++i) if (!f[i])
        for(int j=i*i; j<1000001; j+=i) f[j] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    eratos();
    cin >> t;
    while (t--) {
        cin >> n >> e;
        for(int i=1; i<=n; ++i) cin >> a[i], L[i] = R[i] = 0;
        for(int i=1; i<=n; ++i) if (!f[a[i]]) {
            int j = i + e, dem = 0;
            while (j <= n && a[j] == 1) j += e, ++dem;
            R[i] = dem;
        }
        for(int i=n; i; --i) if (!f[a[i]]) {
            int j = i - e, dem = 0;
            while (j > 0 && a[j] == 1) j -= e, ++dem;
            L[i] = dem;
        }
        res = 0;
        for(int i=1; i<=n; ++i) res += 1LL * (L[i] + 1) * (R[i] + 1) - 1;
        cout << res << '\n';
    }
}