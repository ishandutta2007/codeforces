#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int prev = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';
        int mink = 1e9;
        if (prev > x) {
            mink = min(prev - x, 26 + x - prev);
        } else {
            mink = min(x - prev, 26 + prev - x);
        }
        ans += mink;
        prev = x;
    }
    cout << ans << endl;
}