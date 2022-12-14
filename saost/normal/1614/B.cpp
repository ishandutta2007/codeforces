#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t, n, l, r, k, pos[N];
pair<int,int> a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        long long res = 0;
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i].first, a[i].second = i;
        sort(a+1, a+n+1, greater<pair<int,int>>());
        for(int i=1; i<=n; ++i) {
            pos[a[i].second] = (i+1) / 2 * (i%2==0 ? 1 : -1);
            res += 1LL * (i+1) / 2 * a[i].first;
        }
        cout << res * 2 << '\n';
        for(int i=0; i<=n; ++i) cout << pos[i] << ' ';
        cout << '\n';
    }
}