#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>

using namespace std;

int v[1000];

int
main()
{
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    double res = 0.;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        res = max(res, (v[a] + v[b]) / (c + 0.));
    }
    cout << res << '\n';
    return 0;
}