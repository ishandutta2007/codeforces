#include <bits/stdc++.h>

using namespace std;

//#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> dif;
        for (int i = 0; i < n - 1; i++) {
            dif[a[i + 1] - a[i]]++;
        }
        for (int j = 0; j < n - 2; j++) {
            map<int, int> new_dif;
            for (auto it = dif.begin(); it != dif.end(); it++) {
                new_dif[0] += it->second - 1;
            }
            for (auto it1 = dif.begin(), it2 = ++dif.begin(); it2 != dif.end(); it1++, it2++) {
                new_dif[it2->first - it1->first]++;
            }
            if (new_dif.begin()->second == 0) {
                new_dif.erase(new_dif.begin());
            }
            dif = new_dif;
        }
        cout << dif.begin()->first << '\n';
    }
}