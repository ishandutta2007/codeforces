#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;
string a[111];
int n, m, ans = 0;
set <int> xx, yy;
void rev(int y, int x) {/*
    for (int i = 0; i <= y; i++)
        for (int j = 0; j <= x; j++)
            a[i][j] = (a[i][j] == 'W' ? 'B' : 'W');*/
    yy.insert(y);
    xx.insert(x);
}
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = a[n - 1];
    for (int i = 0; i < m; i++)
        a[n][i] = (a[n - 1][i] == 'W' ? 'B' : 'W');
    for (int i = 0; i <= n; i++)
        a[i] += (a[i][m - 1] == 'W' ? 'B' : 'W');

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (a[i][j + 1] == a[i + 1][j] && (a[i][j] != a[i + 1][j] || a[i + 1][j + 1] != a[i][j + 1]))
            ans++;
        else if (a[i][j] == a[i + 1][j + 1] && (a[i][j] != a[i + 1][j] || a[i][j] != a[i][j + 1]))
            ans++;
    }
    cout << ans;


    return 0;
}