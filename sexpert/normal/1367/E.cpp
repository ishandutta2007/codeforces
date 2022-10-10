#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k, ans = 1;
    cin >> n >> k;
    vector<int> cnt(26);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        cnt[c - 'a']++;
    }
    for(int l = 1; l <= n; l++) {
        int tot = 0;
        int sz = l / __gcd(l, k);
        for(int c = 0; c < 26; c++)
            tot += sz * (cnt[c] / sz);
        if(tot >= l)
            ans = l;
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