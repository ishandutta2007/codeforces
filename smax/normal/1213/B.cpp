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
        int n, a[150000];
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

        int ret = 0, smol = a[n-1];
        for (int i=n-2; i>=0; i--) {
            if (a[i] > smol)
                ret++;
            else
                smol = a[i];
        }

        cout << ret << "\n";
    }

    return 0;
}