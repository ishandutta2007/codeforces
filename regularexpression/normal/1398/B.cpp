#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int cur = 0;
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (cur > 0) arr.push_back(cur);
                cur = 0;
            } else ++cur;
        }
        if (cur > 0) arr.push_back(cur);
        sort(arr.rbegin(), arr.rend());
        int ans = 0;
        for (int i = 0; i < arr.size(); i += 2) ans += arr[i];
        cout << ans << '\n';
    }
    return 0;
}