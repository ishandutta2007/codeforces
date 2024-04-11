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
        int n, x, maxHit = INT_MIN, maxDiff = INT_MIN;
        cin >> n >> x;
        for (int i=0; i<n; i++) {
            int d, h;
            cin >> d >> h;
            maxHit = max(maxHit, d);
            maxDiff = max(maxDiff, d - h);
        }

        if (x <= maxHit)
            cout << "1\n";
        else if (maxDiff <= 0)
            cout << "-1\n";
        else
            cout << ((x - maxHit) % maxDiff == 0 ? (x - maxHit) / maxDiff : (x - maxHit) / maxDiff + 1) + 1 << "\n";
    }

    return 0;
}