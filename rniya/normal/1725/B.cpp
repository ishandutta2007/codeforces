#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long d;
    cin >> n >> d;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        long long t = a[l];
        while (t <= d && l <= r) {
            t += a[l];
            r--;
        }
        if (l <= r) {
            ans++;
        }
        l++;
    }
    cout << ans << endl;
}