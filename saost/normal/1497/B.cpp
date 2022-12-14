#include <iostream>
#include <algorithm>
using namespace std;
int t, n, m, x, res, a[100005], f[100005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        fill(f, f+m+1, 0);
        for(int i=1; i<=n; i++) {
            cin >> x;
            f[x % m]++;
        }
        int res = 0;
        if (f[0]) res++;
        for(int i=1; i<=m/2; i++) {
            x = abs(f[i] - f[m-i]);
            if (!f[i] && !f[m-i]) continue;
            res += max(x, 1);
        }
        cout << res << '\n';
    }
}