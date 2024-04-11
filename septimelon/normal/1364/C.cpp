#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > i + 1) {
            cout << "-1\n";
            return 0;
        }
    }
    
    a.push_back(a.back() + n * 5);
    int ci = 0;
    if (a[0] == 0) {
        while (a[ci + 1] <= a[ci] + 1) {
            ++ci;
        }
        b[0] = a[ci] + 1;
    } else {
        b[0] = 0;
    }
    int mb = b[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            b[i] = a[i - 1];
            mb = max(mb, b[i]);
        } else {
            while (a[ci] < mb) {
                ++ci;
            }
            if (a[ci] > mb + 1) {
                b[i] = mb + 1;
                ++mb;
            } else {
                while (a[ci + 1] <= a[ci] + 1) {
                    ++ci;
                }
                b[i] = a[ci] + 1;
                mb = b[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";   
    }
    
    return 0;
}