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
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (2 * a < b)
            cout << "NO\n";
        else
            cout << ((a + b) % 3 == 0 ? "YES" : "NO") << "\n";
    }

    return 0;
}