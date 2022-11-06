#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int cnt0 = 0, cnt1 = 0;
        while (n--) {
            int kek;
            cin >> kek;
            if (kek & 1) cnt1++; else cnt0++;
        }
        bool ans = 0;
        for (int i = 1; i <= min(cnt1, x); i += 2) {
            if (x - i <= cnt0) {
                ans = 1;
                break;
            }
        }
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}