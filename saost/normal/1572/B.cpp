#include <bits/stdc++.h>

using namespace std;
const int N = 200005;
int t, n, a[N], Q[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i], a[i] ^= a[i-1];
        if (a[n] != 0) {
            cout << "NO\n";
            continue;
        }
        int cnt = 0, n2 = 0;
        for(int i=0; i<=n; ++i) if (a[i] == 0) {
            Q[++cnt] = i;
            if (i & 1) n2 = i;
        }
        if (!n2) cout << "NO\n";
        else {
            cout << "YES\n";
            int res = 0;

            for(int i=1; i<n2-2; i+=2) ++res;
            for(int i=n2-2; i>0; i-=2) ++res;

            for(int i=n2+1; i<n-2; i+=2) ++res;
            for(int i=n-2; i>n2; i-=2) ++res;
            cout << res << '\n';

            for(int i=1; i<n2-2; i+=2) cout << i << ' ';
            for(int i=n2-2; i>0; i-=2) cout << i << ' ';

            for(int i=n2+1; i<n-2; i+=2) cout << i << ' ';
            for(int i=n-2; i>n2; i-=2) cout << i << ' ';

            cout << '\n';
        }
    }
}