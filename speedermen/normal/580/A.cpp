#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a[100010];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int j;
    for (int i = 0; i < n; i = j) {
        j = i + 1;
        while(j < n && a[j] >= a[j - 1]) {
            ++j;
        }
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}