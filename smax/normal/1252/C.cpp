#include <bits/stdc++.h>
using namespace std;

int a[100];

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
        int sum = 0, numZero = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 0)
                numZero++;
        }

        sum += numZero;
        cout << (sum == 0) + numZero << "\n";
    }

    return 0;
}