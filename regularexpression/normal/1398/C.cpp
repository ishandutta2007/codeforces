#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a;
        cin >> n >> a;
        map<int, int> cnt;
        ++cnt[0];
        long long ans = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int val = a[i] - '0' - 1;
            sum += val;
            ans += cnt[sum];
            ++cnt[sum];
        }
        cout << ans << '\n';
    }
    return 0;
}