#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int ind_x[5000001];
int ind_y[5000001];
vector<int> a;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int sum = a[i] + a[j];
            if (ind_x[sum] != 0) {
                if (ind_x[sum] != i + 1 && ind_x[sum] != j + 1 &&
                    ind_y[sum] != i + 1 && ind_y[sum] != j + 1) {
                    cout << "YES" << endl;
                    cout << i + 1 << " " << j + 1 << " " << ind_x[sum] << " " << ind_y[sum] << endl;
                    return 0;
                } else {
                    continue;
                }
            }
            ind_x[sum] = i + 1;
            ind_y[sum] = j + 1;
        }
    }
    cout << "NO" << endl;
}