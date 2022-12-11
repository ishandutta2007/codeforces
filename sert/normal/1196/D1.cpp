#include <bits/stdc++.h>
using namespace std;

const string S = "RGB";

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = n;
    for (int st = 0; st < 3; st++) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (S[(st + i) % 3] != s[i]) num++;
            if (i >= k && S[(st + i - k) % 3] != s[i - k]) num--;
            if (i + 1 >= k) ans = min(ans, num);
        }
    }
    cout << ans << "\n";
}

int main() {
    int t = 0;
    cin >> t;
    while (t--) solve();
    return 0;   
}