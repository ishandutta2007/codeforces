#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int b, g, n, ret = 0;
    cin >> b >> g >> n;
    for (int i=0; i<=n; i++)
        if (i <= b && n - i <= g)
            ret++;
    cout << ret << "\n";

    return 0;
}