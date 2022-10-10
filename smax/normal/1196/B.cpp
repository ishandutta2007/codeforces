#include <bits/stdc++.h>
using namespace std;

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;

        int numSegments = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 1)
                numSegments++;
        }

        if (numSegments < k || numSegments % 2 != k % 2)
            cout << "NO\n";
        else {
            cout << "YES\n";
            int cnt = 0;
            if (k > 1)
            for (int i=0; i<n; i++)
                if (a[i] % 2 == 1) {
                    cout << i+1 << " ";
                    cnt++;
                    if (cnt == k - 1)
                        break;
                }
            cout << n << "\n";
        }
    }

    return 0;
}