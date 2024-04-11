#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 360;
    for(int i = 0; i < n; i++) {
        int s = 0;
        for(int j = i; j < n; j++) {
            s += a[j];
            ans = min(ans, abs(180 - s) * 2);
        }
    }

    cout << ans;
}