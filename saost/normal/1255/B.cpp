#include <iostream>
using namespace std;
const int N = 1005;
int t, n, m, sum, a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        sum = 0;
        for(int i=1; i<=n; ++i) cin >> a[i], sum += a[i];
        if (n == m && n > 2) {
            cout << sum * 2 << '\n';
            for(int i=1; i<n; ++i) cout << i << ' ' << i+1 << '\n';
            cout << n << ' ' << 1 << '\n';
        }
        else cout << -1 << '\n';
    }
}