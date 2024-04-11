#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<int> cnt(105);
    bool twice = true;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(int i = 0; i < 105; i++) {
        if(cnt[i] == 0)
            break;
        if(cnt[i] <= 1)
            twice = false;
        ans += (twice ? 2 : 1);
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