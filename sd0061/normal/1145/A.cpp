#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    for (int w = n ; w > 0 ; w >>= 1) {
        for (int i = 0 ; i < n ; i += w) {
            bool flag = 1;
            for (int j = i ; j < i + w - 1 ; ++ j) {
                if (a[j] > a[j + 1]) {
                    flag = 0;
                }
            }
            if (flag) {
                cout << w << endl;
                return 0;
            }
        }
    }
}