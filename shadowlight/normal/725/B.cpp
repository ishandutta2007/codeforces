#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    long long x = 0, ans;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        long long k = s[i] - '0';
        x = 10 * x + k;
    }
    long long k = s[s.size() - 1] - 'a' + 1;
    long long a = (x - 1) / 4, b = (x - 1) % 4;
    ans = 16 * a;
    if (b == 1 || b == 3) {
        ans += 7;
    }
    if (k <= 3) {
        ans += k + 3;
    } else {
        ans += 7 - k;
    }
    cout << ans << endl;
}