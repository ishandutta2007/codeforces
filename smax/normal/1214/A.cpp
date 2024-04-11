#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, d, e;
    cin >> n >> d >> e;

    int ret = INT_MAX;
    if (d > 5 * e)
        for (int i=0; i<=n/d; i++)
            ret = min(ret, (n - i * d) % (5 * e));
    else
        for (int i=0; i<=n/(5*e); i++)
            ret = min(ret, (n - i * 5 * e) % d);

    cout << ret << "\n";

    return 0;
}