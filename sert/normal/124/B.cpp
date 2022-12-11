#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 34;
const ll INF = 1e9;

ll mn, mx, ans = INF;
ll n, m, x, p[10];    
char a[10][10], b[10][10];

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < m; i++)
        p[i] = i;

    while (true) {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[i][p[j]] = a[i][j];

        mx = -INF;
        mn = INF;

        for (int i = 0; i < n; i++) {
            x = 0;
            for (int j = 0; j < m; j++)
                x = x * 10 + b[i][j] - '0';
            mn = min(mn, x);
            mx = max(mx, x);
        }

        ans = min(ans, mx - mn);

        if (!next_permutation(p, p + m))
            break;
    }
    cout << ans;
}