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
        int r, b, k;
        cin >> r >> b >> k;

        if (r > b)
            swap(r, b);
        int g = __gcd(r, b);
        r /= g;
        b /= g;

        cout << ((r + b - 2) / r < k ? "OBEY" : "REBEL") << "\n";
    }

    return 0;
}