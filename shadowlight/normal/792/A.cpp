#include <bits/stdc++.h>

using namespace std;

const int INF = 2 * 1e9 + 9;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mink = INF, cnt = 0;
    for (int i = 1; i < n; i++) {
        if (mink > a[i] - a[i - 1]) {
            mink = a[i] - a[i - 1];
            cnt = 1;
        } else if (mink == a[i] - a[i - 1]) {
            cnt++;
        }
    }
    cout << mink << " " << cnt;
}