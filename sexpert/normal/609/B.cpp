#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    ll ans = n*(n - 1)/2;
    while(n--) {
        ll x;
        cin >> x;
        ans -= cnt[x];
        cnt[x]++;
    }
    cout << ans << '\n';
}