#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    double ret = 0;
    for (int i=1; i<=n; i++)
        ret += 1.0 / i;

    cout << fixed << setprecision(10) << ret << "\n";

    return 0;
}