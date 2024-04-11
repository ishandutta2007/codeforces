#include <bits/stdc++.h>
using namespace std;

double dp[100000][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;

    double ret = 0;
    for (int i=1; i<=m; i++)
        ret += i * (pow((double) i / m, n) - pow((double) (i - 1) / m, n));

    cout << fixed << setprecision(10) << ret << "\n";

    return 0;
}