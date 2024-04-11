#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m, ret = 0;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            ret += 2 * a[i];
        }

        if (m < n || n == 2)
            cout << "-1\n";
        else {
            cout << ret << "\n";
            for (int i=1; i<=n-1; i++)
                cout << i << " " << i+1 << "\n";
            cout << n << " 1\n";
        }
    }

    return 0;
}