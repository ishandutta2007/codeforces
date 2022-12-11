#include <bits/stdc++.h>

using namespace std;

int n, ans, a, b;
string s, t;

int main() {
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        a = s[i] - '0';
        b = t[i] - '0';
        ans += min((a + 10 - b) % 10, (b + 10 - a) % 10);
    }
    cout << ans;
    return 0;
}