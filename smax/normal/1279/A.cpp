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
        int r, g, b;
        cin >> r >> g >> b;

        if (r > g + b + 1 || g > r + b + 1 || b > r + g + 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}