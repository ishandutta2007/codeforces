#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int mink = 0;
    for (int i = 0; i < n - 1; i++) {
        if (data[i] + data[i + 1] < k) {
            mink += k - data[i] - data[i + 1];
            data[i + 1] += k - data[i] - data[i + 1];
        }
    }
    cout << mink << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
}