#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 340;
const ll INF = 1e9;

ll a[N][N];
ll s[N], r[N], c[N], p[N];
ll ans, n, m;

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m; 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            c[j] += a[i][j];
            r[i] += a[i][j];
        }
    for (int i = 0; i < 3; i++) cin >> s[i];

    sort(s, s + 3);

    while (true) {

        //cout << s[0] << " " << s[1] << " " << s[2] << "\n";

        p[0] = 0;
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] + r[i - 1];

        if (p[n] != s[0] + s[1] + s[2]) {
            cout << 0;
            return 0;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (p[i] == s[0] && p[i + j] == s[0] + s[1] && i + j < n)
                    ans++;
            }

        p[0] = 0;
        for (int i = 1; i <= m; i++)
            p[i] = p[i - 1] + c[i - 1];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                if (p[i] == s[0] && p[i + j] == s[0] + s[1] && i + j < m)
                    ans++;

        if (!next_permutation(s, s + 3))
            break;
    }

    cout << ans;

    return 0;
}