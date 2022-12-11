#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>

#define y1 yy1
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1003;

ll n;
string s;

ll t[N][N];
ll a[N][N], b[N][N], c[N][N], d[N][N];
ll m, ans, ta;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> t[i + 1][j + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = t[i][j] + max(a[i - 1][j], a[i][j - 1]);

    for (int i = 1; i <= n; i++)
        for (int j = m; j > 0; j--)
            b[i][j] = t[i][j] + max(b[i - 1][j], b[i][j + 1]);

    for (int i = n; i > 0; i--)
        for (int j = 1; j <= m; j++)
            c[i][j] = t[i][j] + max(c[i + 1][j], c[i][j - 1]);

    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--)
            d[i][j] = t[i][j] + max(d[i + 1][j], d[i][j + 1]);

    for (int i = 2; i <= n - 1; i++)
        for (int j = 2; j <= m - 1; j++) {
            ta = a[i][j - 1] + d[i][j + 1] + b[i - 1][j] + c[i + 1][j];
            ans = max(ans, ta);
            ta = a[i - 1][j] + d[i + 1][j] + b[i][j + 1] + c[i][j - 1];
            ans = max(ans, ta);
        }

    cout << ans;



    return 0;
}