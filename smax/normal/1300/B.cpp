#include <bits/stdc++.h>
using namespace std;

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n *= 2;
        for (int i=0; i<n; i++)
            cin >> a[i];

        sort(a, a + n);
        int ret = INT_MAX;
        for (int i=0; i<n/2; i++) {
            ret = min(ret, a[n/2] - a[i]);
        }
        for (int i=n/2; i<n; i++)
            ret = min(ret, a[i] - a[n/2-1]);
        cout << ret << "\n";
    }

    return 0;
}