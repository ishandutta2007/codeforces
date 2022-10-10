#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, int> ct;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll p, k, ans = 0;
    cin >> n >> p >> k;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll y = (x * x) % p;
        y = (y * y) % p;
        y = (y - k * x) % p;
        if(y < 0)
            y += p;
        ans += ct[y];
        ct[y]++;
    }

    cout << ans << endl;
}