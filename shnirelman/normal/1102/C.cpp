#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += (a[i] <= x);
    }

    cout << (x <= y ? (cnt + 1) / 2 : n);

}