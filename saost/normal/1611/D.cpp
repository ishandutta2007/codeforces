#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 200005;
int t, n, root, a[N], avail[N], f[N], ans[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        root = 0;
        for(int i=1; i<=n; ++i) {
            cin >> a[i];
            if (a[i] == i) root = i;
            avail[i] = f[i] = 0;
        }
        avail[root] = 1;
        bool ok = true;
        int d = 0, w;
        for(int i=1; i<=n; ++i) {
            cin >> w;
            if (i == 1 && w != root) ok = false;
            if (!avail[a[w]]) ok = false;
            avail[w] = 1;
            f[w] = ++d;
            ans[w] = f[w] - f[a[w]];
        }
        if (!ok) cout << -1 << '\n';
        else {
            for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
            cout << '\n';
        }
    }
}