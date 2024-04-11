#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(1 << k, 0);
    for(int i = 0; i < n; i++) {
        vector<int> b(k);
        int a1 = 0;
        for(int j = 0; j < k; j++) {
            cin >> b[j];
            a1 += (b[j] << j);
        }

        a[a1]++;
    }

    bool ans = false;
    for(int i = 0; i < (1 << k); i++)
        for(int j = 0; j < (1 << k); j++) {
            if(a[j] > 0 && a[i] > 0 && (i & j) == 0)
                ans = true;
        }

    cout << (ans ? "yes" : "no");
}