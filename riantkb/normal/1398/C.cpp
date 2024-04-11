#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        string s;
        cin >> n >> s;
        long long ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += s[i] - '0' - 1;
            ans += mp[sum];
            ++mp[sum];
        }
        cout << ans << '\n';
    }

    return 0;
}