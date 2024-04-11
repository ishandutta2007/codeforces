#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int s;
    string n;
    cin >> n >> s;
    ll big = LLONG_MAX, smol = stoll(n);
    while(n.size() < 19)
        n = "0" + n;
    //cout << n << '\n';

    string ans = "0000000000000000000";
    for(int i = 0; i < 19; i++) {
        if(n[i] != '9') {
            ans[i] = (n[i] + 1);
            if(s >= ((n[i] - '0') + 1))
                big = min(big, stoll(ans));
        }
        ans[i] = n[i];
        s -= (n[i] - '0');
    }
    if(s >= 0)
        big = min(big, stoll(ans));
    //cout << ans << '\n';
    cout << big - smol << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}