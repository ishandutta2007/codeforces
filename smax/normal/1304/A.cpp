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
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if ((y - x) % (a + b) == 0)
            cout << (y - x) / (a + b) << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}