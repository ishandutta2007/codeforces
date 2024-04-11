#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
const int N = 2e5 + 5;
int t, n, m, k, d[N], dem[N];
vector<int> Q[N];
pair<int,int> a[N];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        bool ok = true;
        cin >> n >> m;
        fill(dem+1, dem+n+1, 0);
        fill(d+1, d+m+1, 0);
        for(int i=1; i<=n; i++) Q[i].clear();
        for(int i=1; i<=m; i++) {
            cin >> k;
            int x;
            for(int j=1; j<=k; j++) {
                cin >> x;
                Q[x].push_back(i);
            }
            if (k == 1 && ++dem[x] > (m+1)/2) ok = false;
            if (k == 1) d[i] = x;
        }
        if (!ok) { cout << "NO\n"; continue; }
        cout << "YES\n";
        for(int i=1; i<=n; i++) a[i] = {dem[i], i};
        sort(a+1, a+n+1, greater<pair<int,int>>());
        for(int i=1; i<=n; i++) {
            int sl = (m+1)/2 - a[i].first;
            for(int v : Q[a[i].second]) {
                if (sl && !d[v]) d[v] = a[i].second, sl--;
            }
        }
        for(int i=1; i<=m; i++) cout << d[i] << ' ';
        cout << '\n';
    }
}