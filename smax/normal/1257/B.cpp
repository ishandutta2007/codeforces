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
        int x, y;
        cin >> x >> y;

        if (x >= y)
            cout << "YES\n";
        else if (x == 3 || x == 2 && y > 3 || x == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}