#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500 + 7;

int d[N][N];
int n, l, r, res;
int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        d[1][i] = d[0][i] = 1;

    for (int len = 1; len < n; len++)
    for (int i = 0; i + len < n; i++) {
        l = i;
        r = i + len;
        res = d[len][i] + 1;
        for (int j = l; j < r; j++)
            if (a[j] == a[r])
                res = min(res, (l == j ? 0 : d[j - l][l]) + d[r - j - 1][j + 1]);
        d[len + 1][i] = res;
    }

    cout << d[n][0];

    return 0;
}