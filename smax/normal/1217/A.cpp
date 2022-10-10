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
        int s, i, e;
        cin >> s >> i >> e;
        cout << max(0, e - max(0, (e + i - s + 2) / 2) + 1) << "\n";
    }

    return 0;
}