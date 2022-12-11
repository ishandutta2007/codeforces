#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll n, m, x, y;
ll a[N], b[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m;
    cin >> x >> y;
    for (int i = 0; i < n; cin >> a[i++]);
    for (int i = 0; i < m; cin >> b[i++]);
    cout << (a[x - 1] < b[m - y] ? "YES\n" : "NO\n");
    return 0;
}