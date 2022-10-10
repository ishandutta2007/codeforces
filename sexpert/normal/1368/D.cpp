#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ans = 0;
    vector<int> cnt(20);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int b = 0; b < 20; b++)
            if(x & (1 << b))
                cnt[b]++;
    }
    for(int i = 0; i < n; i++) {
        ll x = 0;
        for(int b = 0; b < 20; b++) {
            if(cnt[b]) {
                x += (1 << b);
                cnt[b]--;
            }
        }
        ans += x * x;
    }
    cout << ans << '\n';
}