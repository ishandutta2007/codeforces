#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> p(n);
        for (int i = 1; i < n-1; i++) {
            p[i] = p[i-1];
            if (a[i] > a[i-1] && a[i] > a[i+1]) p[i]++;
        }

        int parts = -1;
        int border = -1;
        for (int i = 0; i+k <= n; i++) {
            int num;
            if (k > 2) num = p[i+k-2] - p[i];
            else num = 0;

            if (num > parts) {
                parts = num;
                border = i+1;
            }
        }
        cout << parts+1 << " " << border << '\n';
    }
    return 0;
}