#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;
ll res = -1;

int n, m, ta, tb, k;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> ta >> tb >> k;
    if(k >= n || k >= m) return cout << -1 << endl, 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int p = 0; p <= k; p++) {
        int id = (int)(lower_bound(b, b + m, a[p] + ta) - b);
        if(id + k - p >= m) res = INF;
        else res = max(res, 1LL * b[id + k - p] + tb);
    }
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
}