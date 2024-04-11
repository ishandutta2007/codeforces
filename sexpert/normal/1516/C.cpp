#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int g = v[0];
    for(int i = 1; i < n; i++)
        g = __gcd(g, v[i]);
    for(auto &x : v)
        x /= g;
    int s = accumulate(v.begin(), v.end(), 0);
    if(s % 2) {
        cout << "0\n";
        return 0;
    }
    int ta = s/2;
    vector<int> dp(ta + 1);
    dp[0] = 1;
    for(auto &x : v) {
        for(int i = ta; i >= x; i--)
            dp[i] |= dp[i - x];
    }
    if(!dp[ta]) {
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(v[i] % 2) {
            cout << "1\n" << i + 1 << '\n';
            return 0;
        }
    }
}