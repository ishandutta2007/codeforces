#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];

        sort(a.begin(), a.end());

        int ans = (a[0] + a[1] + a[2]) / 2;
        ans = min(ans, a[0] + a[1]);

        cout << ans << endl;
    }
}