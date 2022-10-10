#include <bits/stdc++.h>
using namespace std;

int p[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> p[i];
            if (p[i] == 1)
                l = r = i;
        }

        for (int m=1; m<=n; m++) {
            while (l > 0 && p[l-1] <= m)
                l--;
            while (r < n - 1 && p[r+1] <= m)
                r++;
            cout << (r - l + 1 == m);
        }
        cout << "\n";
    }

    return 0;
}