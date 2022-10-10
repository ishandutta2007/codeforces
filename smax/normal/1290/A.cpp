#include <bits/stdc++.h>
using namespace std;

int a[3500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i=0; i<n; i++)
            cin >> a[i];

        k = min(k, m - 1);
        int ret = 0;
        for (int i=0; i<=k; i++) {
            int guarantee = INT_MAX;
            for (int j=0; j<=m-k-1; j++)
                guarantee = min(guarantee, max(a[i+j], a[n+i+j-m]));
            ret = max(ret, guarantee);
        }

        cout << ret << "\n";
    }

    return 0;
}