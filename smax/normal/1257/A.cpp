#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if (a > b)
            swap(a, b);

        int diff = min(x, a - 1);
        x -= diff, a -= diff;
        diff = min(x, n - b);
        x -= diff, b += diff;

        cout << b - a << "\n";
    }

    return 0;
}