#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int t, n, d, cnt, res, a[N], avail[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        res = 0;
        cin >> n >> d;
        for(int i=0; i<n; ++i) cin >> a[i], avail[i] = 0;
        for(int i=0; i<n; ++i) if (!avail[i] && a[i] == 0) {
            cnt = 0;
            for(int j = i; !avail[j]; j = (j+d) % n) {
                if (a[j] == 1) res = max(res, ++cnt);
                else cnt = 0;
                avail[j] = 1;
            }
        }
        for(int i=0; i<n; ++i) if (!avail[i]) res = -1;
        cout << res << '\n';
    }
}