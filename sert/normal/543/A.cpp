#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const ll N = 501;

ll n, m, b, md;
ll a[N], c[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m >> b >> md;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    c[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = a[i]; j <= b; j++)
            for (int str = 1; str <= m; str++)
                c[j][str] = (c[j][str] + c[j - a[i]][str - 1]) % md;

    ll ans = 0;
    for (int i = 0; i <= b; i++)
        ans = (ans + c[i][m]) % md;

    cout << ans;

    return 0;
}