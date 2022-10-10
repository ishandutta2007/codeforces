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

        int diff = abs(a - b);
        cout << diff / 5 + diff % 5 / 2 + diff % 5 % 2 << "\n";
    }

    return 0;
}