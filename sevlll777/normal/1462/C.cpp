#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<string> ANS(1000, "ah");
    for (int mask = 1; mask < (1 << 10); mask++) {
        int sum = 0;
        vector<int> digits;
        for (int i = 1; i < 10; i++) {
            if ((mask >> i) & 1) {
                digits.pb(i);
                sum += i;
            }
        }
        sort(digits.begin(), digits.end());
        ANS[sum] = "";
        for (auto c : digits) ANS[sum] += (char) ('0'+c);
    }
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (ANS[x] == "ah") {
            cout << "-1\n";
        } else {
            cout << ANS[x] << '\n';
        }
    }
}