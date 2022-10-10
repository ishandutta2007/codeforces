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
        int h, m;
        cin >> h >> m;

        int tm = 60 * h + m;
        cout << 1440 - tm << "\n";
    }

    return 0;
}