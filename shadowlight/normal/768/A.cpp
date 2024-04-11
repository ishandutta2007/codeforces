#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = n - 2;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) break;
        cnt--;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) break;
        cnt--;
    }
    cout << max(cnt, 0);
}