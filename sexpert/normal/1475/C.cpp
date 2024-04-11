#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bin(ll x) {
    return x * (x - 1)/2;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> d1(a), d2(b);
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        d1[x - 1]++;
    }
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        d2[x - 1]++;
    }
    ll ans = bin(k);
    for(int i = 0; i < a; i++)
        ans -= bin(d1[i]);
    for(int i = 0; i < b; i++)
        ans -= bin(d2[i]);
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