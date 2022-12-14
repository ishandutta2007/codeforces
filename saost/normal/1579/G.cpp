#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 2000, INF = 0x3c3c3c3c;
int t, n, res, a[N], f[M], f2[M];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        for(int i=0; i<M; ++i) f[i] = INF;
        f[0] = 0;
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        for(int i=1; i<=n; ++i) {
            int x = a[i];
            for(int j=0; j<M; ++j) f2[j] = f[j], f[j] = INF;
            for(int j=0; j<M; ++j) {
                if (f2[j] == INF) continue;
                if (j >= x)
                    f[j - x] = min(f[j - x], f2[j]);
                else
                    f[0] = min(f[0], f2[j] + x - j);
                if (j + x <= f2[j])
                    f[j + x] = min(f[j + x], f2[j]);
                else
                    f[0] = min(f[0], j + x);
            }
        }
        res = INF;
        for(int i=0; i<M; ++i) res = min(res, f[i]);
        cout << res << '\n';
    }
}