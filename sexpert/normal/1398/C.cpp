#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s >> s;
    map<int, int> cnt;
    ll ans = 0;
    cnt[0] = 1;
    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        cur += (s[i] - '0');
        ans += cnt[cur - i - 1];
        cnt[cur - i - 1]++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}