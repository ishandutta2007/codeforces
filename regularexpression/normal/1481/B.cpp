#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k--;
        vector<int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        vector<int> res;
        while (true) {
            int i = 0;
            while (i < n - 1) {
                if (h[i] >= h[i + 1])
                    i++;
                else {
                    h[i]++;
                    break;
                }
            }
            if (i == n - 1)
                break;
            res.push_back(i + 1);
        }
        cout << (k >= res.size() ? -1 : res[k]) << "\n";
    }
    return 0;
}