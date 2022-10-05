#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#define int long long
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    string ans;
    ans += s[0];
    string mayans = ans + ans;
    for (int i = 1; i < n; ++i) {
        if (s[i] <= s[i - 1]) {
            ans += s[i];
        } else {
            break;
        }
    }
    string revans = ans;
    reverse(revans.begin(), revans.end());
    ans += revans;
    cout << min(ans, mayans) << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}